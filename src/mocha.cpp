#include "mocha.h"

Mocha::Mocha()
{
    this->name = "Mocha";
    this->ingredients.push_back(new Espresso(2));
    this->ingredients.push_back(new Milk(2));
    this->ingredients.push_back(new MilkFoam(1));
    this->ingredients.push_back(new Chocolate(1));
}

Mocha::Mocha(const Mocha& moc)
{
    *this = moc;
}

Mocha::~Mocha()
{
    for (const auto& i : side_items)
        delete i;
    side_items.clear();
}

void Mocha::operator=(const Mocha& moc)
{
    if (this == &moc)
        return;

    this->name = moc.name;

    ingredients.clear();
    for (auto& ptr_ing : moc.get_ingredients()) {
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
    for (const auto& ptr_side_ing : moc.side_items) {
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

std::string Mocha::get_name()
{
    return this->name;
}

double Mocha ::price()
{
    double price { static_cast<double>(Espresso(2).get_units() * Espresso(2).get_price_unit() + Milk(2).get_units() * Milk(2).get_price_unit() + MilkFoam(1).get_units() * MilkFoam(1).get_price_unit() + Chocolate(1).get_units() * Chocolate(1).get_price_unit()) };
    for (const auto& ptr_side_ing : side_items)
        price += ptr_side_ing->get_units() * ptr_side_ing->get_price_unit();
    return price;
}

void Mocha::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items()
{
    return side_items;
}