#include "cappuccino.h"

Cappuccino::Cappuccino(const Cappuccino& cap)
{
    std::cout << "Cappuccino Copy Constructor" << std::endl;
    *this = cap;
}

Cappuccino::~Cappuccino()
{
    for (const auto& i : side_items)
        delete i;
    side_items.clear();
}

void Cappuccino::operator=(const Cappuccino& cap)
{
    std::cout << "Cappuccino operator=" << std::endl;
    this->name = cap.name;
    this->units = cap.units;
    this->price_unit = cap.price_unit;
    for (const auto& ptr : cap.side_items)
        this->side_items.push_back(*(new Ingredient*(ptr)));
}

std::string Cappuccino::get_name()
{
    return this->name;
}

std::vector<Ingredient*>& Cappuccino::get_side_items()
{
    return side_items;
}