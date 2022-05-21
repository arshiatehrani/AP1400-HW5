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
    for (const auto& ptr_ing : cap.ingredients)
        this->ingredients.push_back(ptr_ing);

    for (const auto& ptr_side_ing : cap.side_items)
        this->side_items.push_back(ptr_side_ing);
}

std::string Cappuccino::get_name()
{
    return this->name;
}

double Cappuccino ::price()
{
    double price { static_cast<double>(Espresso(2).get_units() * Espresso(2).get_price_unit() + Milk(2).get_units() * Milk(2).get_price_unit() + MilkFoam(2).get_units() * MilkFoam(2).get_price_unit()) };
    for (const auto& ptr_side_ing : side_items)
        price += ptr_side_ing->get_units() * ptr_side_ing->get_price_unit();
    return price;
}

void Cappuccino::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items()
{
    return side_items;
}