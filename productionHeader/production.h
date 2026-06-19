#ifndef PRODUCTION_H
#define PRODUCTION_H

#include "../nlohmann/json.hpp"
using json = nlohmann::json;

void addProduct(int value, std::string name);

#endif