#include "cappuccino.h"

Cappuccino::Cappuccino()
{
    this->name = "Cappuccino";
    this->ingredients.push_back(new Espresso(2));
    this->ingredients.push_back(new Milk(2));
    this->ingredients.push_back(new MilkFoam(2));
}

Cappuccino::Cappuccino(const Cappuccino& cap)
{
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
    if (this == &cap)
        return;

    this->name = cap.name;

    ingredients.clear();
    for (auto& ptr_ing : cap.get_ingredients()) {
        if (ptr_ing->get_name() == "Cinnamon")
            this->ingredients.push_back(new Cinnamon(ptr_ing->get_units()));
        if (ptr_ing->get_name() == "Chocolate")
            this->ingredients.push_back(new Chocolate(ptr_ing->get_units()));
        if (ptr_ing->get_name() == "Sugar")
            this->ingredients.push_back(new Sugar(ptr_ing->get_units()));
        if (ptr_ing->get_name() == "Cookie")
            this->ingredients.push_back(new Cookie(ptr_ing->get_units()));
        if (ptr_ing->get_name() == "Espresso")
            this->ingredients.push_back(new Espresso(ptr_ing->get_units()));
        if (ptr_ing->get_name() == "Milk")
            this->ingredients.push_back(new Milk(ptr_ing->get_units()));
        if (ptr_ing->get_name() == "MilkFoam")
            this->ingredients.push_back(new MilkFoam(ptr_ing->get_units()));
        if (ptr_ing->get_name() == "Water")
            this->ingredients.push_back(new Water(ptr_ing->get_units()));
    }

    side_items.clear();
    for (const auto& ptr_side_ing : cap.side_items) {
        if (ptr_side_ing->get_name() == "Cinnamon")
            this->side_items.push_back(new Cinnamon(ptr_side_ing->get_units()));
        if (ptr_side_ing->get_name() == "Chocolate")
            this->side_items.push_back(new Chocolate(ptr_side_ing->get_units()));
        if (ptr_side_ing->get_name() == "Sugar")
            this->side_items.push_back(new Sugar(ptr_side_ing->get_units()));
        if (ptr_side_ing->get_name() == "Cookie")
            this->side_items.push_back(new Cookie(ptr_side_ing->get_units()));
        if (ptr_side_ing->get_name() == "Espresso")
            this->side_items.push_back(new Espresso(ptr_side_ing->get_units()));
        if (ptr_side_ing->get_name() == "Milk")
            this->side_items.push_back(new Milk(ptr_side_ing->get_units()));
        if (ptr_side_ing->get_name() == "MilkFoam")
            this->side_items.push_back(new MilkFoam(ptr_side_ing->get_units()));
        if (ptr_side_ing->get_name() == "Water")
            this->side_items.push_back(new Water(ptr_side_ing->get_units()));
    }
}

std::string Cappuccino::get_name()
{
    return this->name;
}

double Cappuccino ::price()
{
    double price { static_cast<double>(Espresso(2).get_units() * Espresso(2).get_price_unit() + Milk(2).get_units() * Milk(2).get_price_unit() + MilkFoam(1).get_units() * MilkFoam(1).get_price_unit()) };
    for (const auto& ptr_side_ing : side_items)
        price += ptr_side_ing->get_units() * ptr_side_ing->get_price_unit();
    return price;
}

void Cappuccino::add_side_item(Ingredient* side)
{
    if (side->get_name() == "Cinnamon")
        side_items.push_back(new Cinnamon(side->get_units()));
    if (side->get_name() == "Chocolate")
        side_items.push_back(new Chocolate(side->get_units()));
    if (side->get_name() == "Sugar")
        side_items.push_back(new Sugar(side->get_units()));
    if (side->get_name() == "Cookie")
        side_items.push_back(new Cookie(side->get_units()));
    if (side->get_name() == "Espresso")
        side_items.push_back(new Espresso(side->get_units()));
    if (side->get_name() == "Milk")
        side_items.push_back(new Milk(side->get_units()));
    if (side->get_name() == "MilkFoam")
        side_items.push_back(new MilkFoam(side->get_units()));
    if (side->get_name() == "Water")
        side_items.push_back(new Water(side->get_units()));
}

std::vector<Ingredient*>& Cappuccino::get_side_items()
{
    return side_items;
}