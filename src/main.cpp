#include "cappuccino.h"
#include "espresso_based.h"
#include "ftxui/component/captured_mouse.hpp" // for ftxui
#include "ftxui/component/component.hpp" // for Input, Renderer, Vertical
#include "ftxui/component/component.hpp" // for Radiobox, Renderer, Tab, Toggle, Vertical
#include "ftxui/component/component_base.hpp" // for ComponentBase
#include "ftxui/component/screen_interactive.hpp" // for Component, ScreenInteractive
#include "ftxui/component/screen_interactive.hpp" // for ScreenInteractive
#include "ftxui/dom/canvas.hpp"
#include "ftxui/dom/elements.hpp" // for operator|, Element, size, border, frame, vscroll_indicator, HEIGHT, LESS_THAN
#include "ftxui/dom/elements.hpp" // for Element, separator, operator|, vbox, border
#include "ftxui/dom/flexbox_config.hpp"
#include "ftxui/dom/node.hpp"
#include "ftxui/screen/box.hpp"
#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/terminal.hpp"
#include "ftxui/util/ref.hpp"
#include "ingredient.h"
#include "mocha.h"
#include "sub_ingredients.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <memory> // for allocator, __shared_ptr_access, shared_ptr
#include <string> // for string, basic_string
#include <vector> // for vector

#include <gtest/gtest.h>
#include <iostream>
int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section

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