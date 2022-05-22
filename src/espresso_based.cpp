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

void EspressoBased ::brew()
{
    using namespace ftxui;
    using namespace std::chrono_literals;

    std::queue<std::string> ing;
    for (const auto& ing_it : this->get_ingredients())
        ing.push(ing_it->get_name());

    // Top Box containing the name of coffee
    auto box_top { dbox({ text(this->get_name()) | bgcolor(Color::DarkRed) | bold | center | border }) };
    auto screen_box_top { Screen::Create(Dimension::Full(), Dimension::Fit(box_top)) };
    Render(screen_box_top, box_top);
    screen_box_top.Print();

    // Drawing the Ingredients
    for (const auto& ing_it : this->get_ingredients()) {

        auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(box_top));
        std::string reset_position;

        // Each Ingredient
        for (double percentage { 0.0f }; percentage <= 1.01f; percentage += 0.007f) {
            std::string String_percent { std::to_string(int(percentage * 100)) + "/100" };

            if (ing.empty())
                break;

            auto ing_name { ing_it->get_name() };

            if (ing.front() == "Cinnamon") {

                auto filling { hbox({ text(ing_name + " :  \t") | color(Color::RGB(123, 63, 0)),
                    gauge(percentage) | color(Color::RGB(123, 63, 0)),
                    text(" " + String_percent) }) };
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.05s);

            } else if (ing.front() == "Chocolate") {

                auto filling { hbox({ text(ing_name + " :  \t") | color(Color::RGB(92, 51, 23)),
                    gauge(percentage) | color(Color::RGB(92, 51, 23)),
                    text(" " + String_percent) }) };
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.05s);

            } else if (ing.front() == "Sugar") {

                auto filling { hbox({ text(ing_name + " :  \t") | color(Color::RGB(244, 238, 232)),
                    gauge(percentage) | color(Color::RGB(244, 238, 232)),
                    text(" " + String_percent) }) };
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.05s);

            } else if (ing.front() == "Cookie") {

                auto filling { hbox({ text(ing_name + " :  \t") | color(Color::RGB(157, 126, 103)),
                    gauge(percentage) | color(Color::RGB(157, 126, 103)),
                    text(" " + String_percent) }) };
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.05s);

            } else if (ing.front() == "Espresso") {

                auto filling { hbox({ text(ing_name + " :  \t") | color(Color::RGB(60, 34, 24)),
                    gauge(percentage) | color(Color::RGB(60, 34, 24)),
                    text(" " + String_percent) }) };
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.05s);

            } else if (ing.front() == "Milk") {

                auto filling { hbox({ text(ing_name + " :  \t") | color(Color::RGB(255, 255, 255)),
                    gauge(percentage) | color(Color::RGB(255, 255, 255)),
                    text(" " + String_percent) }) };
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.05s);

            } else if (ing.front() == "MilkFoam") {

                auto filling { hbox({ text(ing_name + " :  \t") | color(Color::RGB(219, 168, 88)),
                    gauge(percentage) | color(Color::RGB(219, 168, 88)),
                    text(" " + String_percent) }) };
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.05s);

            } else if (ing.front() == "Water") {

                auto filling { hbox({ text(ing_name + " :  \t") | color(Color::RGB(128, 197, 222)),
                    gauge(percentage) | color(Color::RGB(128, 197, 222)),
                    text(" " + String_percent) }) };
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.05s);
            }
        }
        ing.pop();
    }
    std::string reset_position;

    auto box_bottom { ftxui::dbox({ ftxui::text("DONE!!!111!!") | ftxui::bgcolor(ftxui::Color::Green) | ftxui::bold | ftxui::center | ftxui::border }) };
    auto screen_box_bottom { ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(box_bottom)) };
    ftxui::Render(screen_box_bottom, box_bottom);
    screen_box_bottom.Print();
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