#include "../include/Dog.h"
#include "../include/Cat.h"
#include "../include/Parrot.h"
#include "../include/Fish.h"
#include "../include/Pig.h"

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <stdexcept>
#include <vector>




std::string cut_fill(std::string& line, const char& symbol) {
    std::string temp = line.substr(0, line.find(symbol));
    line.erase(0, line.find(symbol) + 1);
    return temp;
}

void ReadFile(const std::string& filename, std::vector<Animal*>& pets) {
    std::ifstream input_file(filename);
    if(!input_file.is_open()) {
        throw std::runtime_error("Input file not found!");
    }
    if(input_file.peek() == std::ifstream::traits_type::eof()) {
        throw std::runtime_error("Input file is empty!");
    }
    std::string line;
    while (std::getline(input_file, line)) {
        std::string o_name;
        std::string adress;
        std::string phone;
        std::string b_date;
        std::string a_type;
        std::string a_name;
        __int16 a_age;
        o_name = cut_fill(line, ';');
        adress = cut_fill(line, ';');
        phone = cut_fill(line, ';');
        b_date = cut_fill(line, ';');
        a_type = cut_fill(line, ';');
        a_name = cut_fill(line, ';');
        if(!line.empty()) {
            a_age = std::stoi(line);
        }
        Owner owner(o_name, adress, phone, b_date);
        if (a_type == "Dog") {
            pets.push_back(new Dog(owner, a_name, a_age)) ;
        } else if (a_type == "Cat") {
            pets.push_back(new Cat(owner, a_name, a_age));
        } else if (a_type == "Parrot") {
            pets.push_back(new Parrot(owner, a_name, a_age));
        } else if (a_type == "Fish") {
            pets.push_back(new Fish(owner, a_name, a_age));
        } else if (a_type == "Pig") {
            pets.push_back(new Pig(owner, a_name, a_age));
        } else {
            throw std::runtime_error("Unknown animal type in input file!");
        }
    }
    input_file.close();
}

void PrintByID(__int16 id, const std::vector<Animal*>& pets) {
    --id;
    std::cout << "ID: " << pets[id]->GetId() << std::endl;
    std::string type = typeid(*pets[id]).name();
    std::cout << "Type: " << type.substr(1) << std::endl;
    std::cout << "Name: " << pets[id]->GetAName() << std::endl;
    std::cout << "Age: " << pets[id]->GetAge() << std::endl;
    std::cout << "Owner name: " << pets[id]->GetOwnerRef().GetOName() << std::endl;
    std::cout << "Adress: " << pets[id]->GetOwnerRef().GetAdress() << std::endl;
    std::cout << "Owner phone: " << pets[id]->GetOwnerRef().GetPhone() << std::endl;
    std::cout << "Owner birth date: " << pets[id]->GetOwnerRef().GetBDate() << std::endl;
    std::cout << "-------------------" << std::endl;
}

void PrintPets(const std::vector<Animal*>& pets) {
    std::cout << "| All animals |\n" << std::endl;
    __int16 size = pets.size();
    for (__int16 i = 1; i <= size; ++i) {
        PrintByID(i, pets);
    }
}

void DifTypesByOwner(const std::vector <Animal*>& pets) {
    std::cout << "| The number of different types of animals each owner has |\n" << std::endl;
    std::map<std::string, std::set<std::string> > owners;
    for (auto& pet : pets) {
        std::string owner_name = pet->GetOwnerRef().GetOName();
        std::string type = typeid(*pet).name();
        type = type.substr(1);
        owners[owner_name].insert(type);
    }
    for (auto& owner : owners) {
        std::cout << "Owner: " << owner.first << std::endl;
        std::cout << "Amount of types: " << owner.second.size() << std::endl;
        std::cout << "Types: ";
        for (auto& type : owner.second) {
            std::cout << type << " ";
        }
        std::cout << "\n-------------------" << std::endl;
    }
}

void OwnersAndNamesByType(const std::vector<Animal*>& pets) {
    std::cout << "| All owners and names of a specific kind of animal |\n" << std::endl;
    std::cout << "Types: Dog, Cat, Parrot, Fish, Pig\n";
    std::string input_type;
    std::cout << "Enter animal type: ";
    std::cin >> input_type;
    try {
        if (input_type != "Dog" && input_type != "Cat" && input_type != "Parrot" && input_type != "Fish" && input_type != "Pig") {
            std::cerr << "Unknown animal type!" << std::endl;
            return;
        }
        std::set<std::string> owners;
        std::set <std::string> names;
        for (auto& pet : pets) {
            std::string type = typeid(*pet).name();
            type = type.substr(1);
            if (type == input_type) {
                owners.insert(pet->GetOwnerRef().GetOName());
                names.insert(pet->GetAName());
            }
        }
        std::cout << "Owner's names: ";
        for (auto& owner : owners) {
            std::cout << owner << " ";
        }
        std::cout << "\nNames: ";
        for (auto& name : names) {
            std::cout << name << " ";
        }
        std::cout << "\n-------------------" << std::endl;
    }
    catch (const char* err) {
        std::cerr << err << std::endl;
    }
}

void AmountOfTypesByName(const std::vector<Animal*>& pets) {
    std::cout  << "| Number of animal species with a specific name |\n" << std::endl;
    std::string input_name;
    std::cout << "Enter animal name: ";
    std::cin >> input_name;
    std::set<std::string> types;
    for (auto& pet : pets) {
        if (pet->GetAName() == input_name) {
            std::string type = typeid(*pet).name();
            type = type.substr(1);
            types.insert(type);
        }
    }
    std::cout << "Amount of types: " << types.size() << std::endl;
    std::cout << "-------------------" << std::endl;
}

void YoungestOldestOfEachSpecies(const std::vector<Animal*>& pets) {
    std::map<std::string, std::set<__int16> > type_ages;
    for (auto& pet : pets) {
        std::string type = typeid(*pet).name();
        type = type.substr(1);
        type_ages[type].insert(pet->GetAge());
    }
    std::cout << "| The youngest and the oldest animal of each species |\n" <<  std::endl;
    for (auto& type : type_ages) {
        std::cout << "Type: " << type.first << std::endl;
        std::cout << "Youngest: " << *type.second.begin() << std::endl;
        std::cout << "Oldest: " << *type.second.rbegin() << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}

void DeletePets(std::vector<Animal*>& pets) {
    for (auto& pet : pets) {
        delete pet;
    }
    pets.clear();
}

void ClaerMemoryAndWriteFile(const std::string& filename, std::vector<Animal*>& pets) {
    std::ofstream output_file(filename);
    try {
        if (!output_file.is_open()){
            throw std::runtime_error("File not found!");
        }
        for (auto& pet : pets) {
                std::string type = typeid(*pet).name();
                type = type.substr(1);
                output_file << pet->GetOwnerRef().GetOName() << ";";
                output_file << pet->GetOwnerRef().GetAdress() << ";";
                output_file << pet->GetOwnerRef().GetPhone() << ";";
                output_file << pet->GetOwnerRef().GetBDate() << ";";
                output_file << type << ";";
                output_file << pet->GetAName() << ";";
                output_file << pet->GetAge() << std::endl;
            }
        output_file.close();
        DeletePets(pets);
    }
    catch (const char* err) {
        std::cerr << err << std::endl;
    }
}

void ChangeOwnerData(Owner& owner) {
    std::cout << "1. Change owner name\n";
    std::cout << "2. Change owner adress\n";
    std::cout << "3. Change owner phone\n";
    std::cout << "4. Change owner birth date\n";
    std::cout << "Enter the number of the action: ";
    __int16 action;
    std::cin >> action;
    std::string temp;
    switch (action) {
        case 1:
            std::cout << "Enter new owner name: ";
            std::cin >> temp;
            owner.SetOName(temp);
            break;
        case 2:
            std::cout << "Enter new owner adress: ";
            std::cin >> temp;
            owner.SetAdress(temp);
            break;
        case 3:
            std::cout << "Enter new owner phone: ";
            std::cin >> temp;
            owner.SetPhone(temp);
            break;
        case 4:
            std::cout << "Enter new owner birth date: ";
            std::cin >> temp;
            owner.SetBDate(temp);
            break;
        default:
            std::cerr << "Unknown action!" << std::endl;
            break;
    }
}

void ChangeAnimalData(std::vector <Animal*>& pets) {
    std::cout << "Enter the ID of the animal you want to change: ";
    __int16 id;
    std::cin >> id;
    if (id > pets.size() || id < 1) {
        std::cerr << "Unknown ID!\n" << std::endl;
        return;
    }
    PrintByID(id, pets);
    --id;
    std::cout << "1. Change owner\n";
    std::cout << "2. Change animal name\n";
    std::cout << "3. Change animal age\n";
    std::cout << "Enter the number of the action: ";
    __int16 action;
    std::cin >> action;
    std::string temp;
    switch (action) {
        case 1:
            ChangeOwnerData(pets[id]->GetOwnerRef());
            break;
        case 2:
            std::cout << "Enter new animal name: ";
            std::cin >> temp;
            pets[id]->SetAName(temp);
            break;
        case 3:
            std::cout << "Enter new animal age: ";
            __int16 age;
            std::cin >> age;
            pets[id]->SetAge(age);
            break;
        default:
            std::cerr << "Unknown action!" << std::endl;
            break;
    }
}

void Do(const std::vector<Animal*>& pets) {
    std::cout << "Enter animal ID: ";
    __int16 id;
    std::cin >> id;
    if (id > pets.size() || id < 1) {
        std::cerr << "Unknown ID!\n" << std::endl;
        return;
    }
    std::string type;
    type = typeid(*pets[id - 1]).name();
    type = type.substr(1);
    std::cout << "Animal type: " << type << std::endl << "Action: ";
    if (type == "Dog") {
        std::cout << "Throw a frisbee";
    } else if (type == "Cat") {
        std::cout << "Pat on the head";
    } else if (type == "Fish") {
        std::cout << "Start feeding";
    } else if (type == "Parrot") {
        std::cout << "To teach a new word";
    } else if (type == "Pig") {
        std::cout << "Scratch";
    }
    std::cout << std::endl;
}

void Menu (std::vector<Animal*>& pets) {
    __int16 action;
    while (true) {
        std::cout << "1. Print all animals\n";
        std::cout << "2. The number of different types of animals each owner has\n";
        std::cout << "3. All owners and names of a specific kind of animal\n";
        std::cout << "4. Number of animal species with a specific name\n";
        std::cout << "5. The youngest and the oldest animal of each species\n";
        std::cout << "6. Change animal data by ID\n";
        std::cout << "7. Do smth with the animal\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter the number of the action: ";
        std::cin >> action;
        switch (action) {
            case 1:
                PrintPets(pets);
                break;
            case 2:
                DifTypesByOwner(pets);
                break;
            case 3:
                OwnersAndNamesByType(pets);
                break;
            case 4:
                AmountOfTypesByName(pets);
                break;
            case 5:
                YoungestOldestOfEachSpecies(pets);
                break;
            case 6:
                ChangeAnimalData(pets);
                break;
            case 7:
                Do(pets);
                break;
            case 0:
                ClaerMemoryAndWriteFile("input.txt", pets);
                return;
            default:
                std::cerr << "Unknown action!" << std::endl;
                break;
        }
    }
}