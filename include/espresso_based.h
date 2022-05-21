#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H
#include "ingredient.h"
#include <iostream>

class EspressoBased {
public:
    virtual std::string get_name() = 0;
    virtual double price() = 0;

    void brew();
    const std::vector<Ingredient*>& get_ingredients() const;

    virtual ~EspressoBased();

protected:
    EspressoBased() = default;
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;
};
#endif // ESPRESSO_BASED_H