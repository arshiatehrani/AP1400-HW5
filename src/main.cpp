#include "cappuccino.h"
#include "espresso_based.h"
#include "ftxui/dom/canvas.hpp"
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
#include <gtest/gtest.h>
#include <iostream>
int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
        using namespace ftxui;
        using namespace std::chrono_literals;

        std::string reset_position;
        for (float percentage = 0.0f; percentage <= 1.0f; percentage += 0.002f) {
            std::string data_downloaded = std::to_string(int(percentage * 100)) + "% / 100%";
            auto document = hbox({
                text("downloading:"),
                gauge(percentage) | flex,
                text(" " + data_downloaded),
            });
            auto screen = Screen(100, 1);
            Render(screen, document);
            std::cout << reset_position;
            screen.Print();
            reset_position = screen.ResetPosition();

            std::this_thread::sleep_for(0.001s);
        }
        std::cout << std::endl;
        // std::string reset_position2;
        // for (float percentage = 0.0f; percentage <= 1.0f; percentage += 0.002f) {
        //     std::string data_downloaded = std::to_string(int(percentage * 5000)) + "/5000";
        //     auto document = hbox({
        //         text("downloading:"),
        //         gauge(percentage) | flex,
        //         text(" " + data_downloaded),
        //     });
        //     auto screen = Screen(100, 1);
        //     Render(screen, document);
        //     std::cout << reset_position2;
        //     screen.Print();
        //     reset_position2 = screen.ResetPosition();

        //     std::this_thread::sleep_for(0.01s);
        // }
        // std::cout << std::endl;

        ////////////////////////////////////////////////////////////////////////////////////////////
        // using namespace ftxui;
        // using namespace std::chrono_literals;

        // std::string reset_position;
        // for (float percentage = 0.0f; percentage <= 1.0f; percentage += 0.002f) {
        //     std::string data_downloaded = std::to_string(int(percentage * 5000)) + "/5000";

        //     auto gauge_up = //
        //         hbox({
        //             vtext("gauge vertical"),
        //             separator(),
        //             gaugeUp(percentage),
        //         })
        //         | border;

        //     auto gauge_down = //
        //         hbox({
        //             vtext("gauge vertical"),
        //             separator(),
        //             gaugeDown(percentage),
        //         })
        //         | border;

        //     auto gauge_right = //
        //         vbox({
        //             text("gauge horizontal"),
        //             separator(),
        //             gaugeRight(percentage),
        //         })
        //         | border;

        //     auto gauge_left = //
        //         vbox({
        //             text("gauge horizontal"),
        //             separator(),
        //             gaugeLeft(percentage),
        //         })
        //         | border;

        //     auto document = hbox({
        //         gauge_up,
        //         filler(),
        //         vbox({
        //             gauge_right,
        //             filler(),
        //             text(data_downloaded) | border | center,
        //             filler(),
        //             gauge_left,
        //         }),
        //         filler(),
        //         gauge_down,
        //     });

        //     auto screen = Screen(32, 16);
        //     Render(screen, document);
        //     std::cout << reset_position;
        //     screen.Print();
        //     reset_position = screen.ResetPosition();

        //     std::this_thread::sleep_for(0.01s);
        // }
        // std::cout << std::endl;
        ////////////////////////////////////////////////////////////////////////////////

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