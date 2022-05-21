#include "espresso_based.h"
EspressoBased ::EspressoBased(const EspressoBased& esp)
{
    std::cout << "Copy Constructor" << std::endl;
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
    return ingredients;
}
void EspressoBased ::operator=(const EspressoBased& esp)
{
    name = esp.name;
    for (const auto& ptr_ing : esp.get_ingredients())
        ingredients.push_back(ptr_ing);
}