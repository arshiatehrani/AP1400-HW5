#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H
#include <iostream>

#define DEFCLASS(sub_ingridient, price_per_unit)              \
    class sub_ingridient : public Ingredient {                \
    public:                                                   \
        sub_ingridient(size_t units)                          \
            : Ingredient { price_per_unit, units }            \
        {                                                     \
            this->name = #sub_ingridient;                     \
        }                                                     \
                                                              \
        virtual std::string get_name() { return this->name; } \
    };

DEFCLASS(Cinnamon, 5);
DEFCLASS(Chocolate, 5);
DEFCLASS(Sugar, 1);
DEFCLASS(Cookie, 10);
DEFCLASS(Espresso, 15);
DEFCLASS(Milk, 10);
DEFCLASS(MilkFoam, 5);
DEFCLASS(Water, 1);

#endif // SUB_INGREDIENTS_H