#include "espresso_based.h"

EspressoBased ::EspressoBased(const EspressoBased& esp)
{
    *this = esp;
}

EspressoBased::~EspressoBased()
{
    for (const auto& i : ingredients)
        delete i;
    ingredients.clear();
}

const std::vector<Ingredient*>& EspressoBased ::get_ingredients() const
{
    return this->ingredients;
}

void EspressoBased ::operator=(const EspressoBased& esp)
{
    if (this == &esp)
        return;
    name = esp.name;
    ingredients.clear();
    for (auto& ptr_ing : esp.get_ingredients()) {
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
}