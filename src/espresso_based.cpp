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
    using namespace std::chrono_literals;
    auto box1 = ftxui::dbox({ ftxui::text(this->get_name()) | ftxui::bgcolor(ftxui::Color::Red) | ftxui::bold | ftxui::center | ftxui::border });
    auto screenbox1 = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(box1));
    ftxui::Render(screenbox1, box1);
    screenbox1.Print();

    std::queue<std::string> q;
    for (auto i : this->get_ingredients())
        q.push(i->get_name());

    for (auto& i : this->get_ingredients()) {

        auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(box1));
        std::string reset_position;

        for (double percentage { 0.0f }; percentage <= 1.01f; percentage += 0.007f) {
            std::string String_percent = std::to_string(int(percentage * 100)) + "/100";

            if (q.empty())
                break;

            auto x = i->get_name();

            // std::setw(5);
            // std::right;
            // std::cout << std::setw(10);
            // auto y = this->get_ingredients();

            if (q.front() == "Cinnamon") {
                auto filling = ftxui::hbox({ // ftxui::hbox({ftxui::text(x)}) | ftxui::border | ftxui::center ,
                    ftxui::text(x + " :  \t") | ftxui::color(ftxui::Color::RGB(123, 63, 0)),
                    ftxui::gauge(percentage) | ftxui::color(ftxui::Color::RGB(123, 63, 0)),
                    ftxui::text(" " + String_percent) });
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.005s);
                // q.pop();
            } else if (q.front() == "Chocolate") {
                auto filling = ftxui::hbox({ // ftxui::hbox({ftxui::text(x)}) | ftxui::border | ftxui::center ,
                    ftxui::text(x + " :  \t") | ftxui::color(ftxui::Color::RGB(92, 51, 23)),
                    ftxui::gauge(percentage) | ftxui::color(ftxui::Color::RGB(92, 51, 23)),
                    ftxui::text(" " + String_percent) });
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.005s);
                // q.pop();
            } else if (q.front() == "Sugar") {
                auto filling = ftxui::hbox({ // ftxui::hbox({ftxui::text(x)}) | ftxui::border | ftxui::center ,
                    ftxui::text(x + " :  \t") | ftxui::color(ftxui::Color::RGB(244, 238, 232)),
                    ftxui::gauge(percentage) | ftxui::color(ftxui::Color::RGB(244, 238, 232)),
                    ftxui::text(" " + String_percent) });
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.005s);
                // q.pop();
            } else if (q.front() == "Cookie") {
                auto filling = ftxui::hbox({ // ftxui::hbox({ftxui::text(x)}) | ftxui::border | ftxui::center ,
                    ftxui::text(x + " :  \t") | ftxui::color(ftxui::Color::RGB(157, 126, 103)),
                    ftxui::gauge(percentage) | ftxui::color(ftxui::Color::RGB(157, 126, 103)),
                    ftxui::text(" " + String_percent) });
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.005s);
                // q.pop();
            } else if (q.front() == "Espresso") {
                auto filling = ftxui::hbox({ // ftxui::hbox({ftxui::text(x)}) | ftxui::border | ftxui::center ,
                    ftxui::text(x + " :  \t") | ftxui::color(ftxui::Color::RGB(60, 34, 24)),
                    ftxui::gauge(percentage) | ftxui::color(ftxui::Color::RGB(60, 34, 24)),
                    ftxui::text(" " + String_percent) });
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.005s);
                // q.pop();
            } else if (q.front() == "Milk") {
                auto filling = ftxui::hbox({ // ftxui::hbox({ftxui::text(x)}) | ftxui::border | ftxui::center ,
                    ftxui::text(x + " :  \t") | ftxui::color(ftxui::Color::RGB(255, 255, 255)),
                    ftxui::gauge(percentage) | ftxui::color(ftxui::Color::RGB(255, 255, 255)),
                    ftxui::text(" " + String_percent) });
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.005s);
                // q.pop();
            } else if (q.front() == "MilkFoam") {
                auto filling = ftxui::hbox({ // ftxui::hbox({ftxui::text(x)}) | ftxui::border | ftxui::center ,
                    ftxui::text(x + " :  \t") | ftxui::color(ftxui::Color::RGB(219, 168, 88)),
                    ftxui::gauge(percentage) | ftxui::color(ftxui::Color::RGB(219, 168, 88)),
                    ftxui::text(" " + String_percent) });
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.005s);
                // q.pop();
            } else if (q.front() == "Water") {
                auto filling = ftxui::hbox({ // ftxui::hbox({ftxui::text(x)}) | ftxui::border | ftxui::center ,
                    ftxui::text(x + " :  \t") | ftxui::color(ftxui::Color::RGB(128, 197, 222)),
                    ftxui::gauge(percentage) | ftxui::color(ftxui::Color::RGB(128, 197, 222)),
                    ftxui::text(" " + String_percent) });
                Render(screen, filling);
                std::cout << reset_position;
                screen.Print();
                reset_position = screen.ResetPosition();
                std::this_thread::sleep_for(0.005s);
                // q.pop();
            }
        }

        q.pop();
    }
    std::string reset_position;
    // auto b2 = ftxui::dbox({ ftxui::text("Your " + this->get_name() + " is ready. ENJOY!!") | ftxui::color(ftxui::Color::Green) | ftxui::bold | ftxui::center });
    // auto screenb2 = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(b2));
    // ftxui::Render(screenb2, b2);
    // screenb2.Print();
    auto box2 = ftxui::dbox({ ftxui::text("DONE!!!111!!") | ftxui::bgcolor(ftxui::Color::Green) | ftxui::bold | ftxui::center | ftxui::border });
    auto screenbox2 = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(box2));
    ftxui::Render(screenbox2, box2);
    screenbox2.Print();
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