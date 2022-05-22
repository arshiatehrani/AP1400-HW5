#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H
#include "ingredient.h"
#include "sub_ingredients.h"
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "ftxui/dom/node.hpp" // for Render
#include "ftxui/screen/color.hpp" // for ftxui
#include <chrono> // for operator""s, chrono_literals
#include <ftxui/dom/elements.hpp> // for text, gauge, operator|, flex, hbox, Element
#include <ftxui/screen/screen.hpp> // for Screen
#include <iomanip>
#include <random>
#include <thread> // for sleep_for

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