#include "cappuccino.h"
#include "espresso_based.h"
#include "ingredient.h"
#include "mocha.h"
#include "sub_ingredients.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <gtest/gtest.h>
#include <iostream>
int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
        Cappuccino cappuccino;
        cappuccino.add_side_item(new Water { 1 });
        Cappuccino equal;
        equal.add_side_item(new Sugar { 1 });
        equal = cappuccino;
        std::cout << "equal: " << equal.price() << "cappuccino: " << cappuccino.price() << std::endl;
        std::cout << "equal: " << equal.get_ingredients().size() << "cappuccino: " << cappuccino.get_ingredients().size() << std::endl;

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}