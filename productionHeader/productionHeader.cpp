#include <iostream>
#include <fstream>

#include "production.h"
#include "../nlohmann/json.hpp"

using json = nlohmann::json;

void addProduct(int value, std::string name) {
    std::string inventoryPath = "inventory.json";

    std::ifstream file(inventoryPath);
    if (!file.is_open()) {std::cout << "File failed to open!"; return;}

    json inventory;
    file >> inventory;

    int currentInvAmount = inventory["amount"];

    inventory["amount"] = currentInvAmount + 1;
    inventory["inventory"][name+std::to_string(currentInvAmount+1)]["value"] = value;

    std::ofstream outFile(inventoryPath);
    if (outFile.is_open()) {
        outFile << inventory.dump(4);
        outFile.close();
    } 
    else {
        std::cerr << "Error: Could not open the file for writing!" << std::endl;
    }
};