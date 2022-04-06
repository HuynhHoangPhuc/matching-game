//
// Created by Phuc Huynh Hoang on 17/03/2022.
//

#include "Utilities.h"

void Utilities::printColor(const std::string &text,
                           const std::string &color,
                           const std::string &decoration) {

    static const std::unordered_map<std::string, std::string> colorCode{
            {"Reset",                     "\u001b[0m"},
            {"Black",                     "\u001b[30m"},
            {"Red",                       "\u001b[31m"},
            {"Green",                     "\u001b[32m"},
            {"Yellow",                    "\u001b[33m"},
            {"Blue",                      "\u001b[34m"},
            {"Magenta",                   "\u001b[35m"},
            {"Cyan",                      "\u001b[36m"},
            {"White",                     "\u001b[37m"},
            {"Bright_Black",              "\u001b[30;1m"},
            {"Bright_Red",                "\u001b[31;1m"},
            {"Bright_Green",              "\u001b[32;1m"},
            {"Bright_Yellow",             "\u001b[33;1m"},
            {"Bright_Blue",               "\u001b[34;1m"},
            {"Bright_Magenta",            "\u001b[35;1m"},
            {"Bright_Cyan",               "\u001b[36;1m"},
            {"Bright_White",              "\u001b[37;1m"},
            {"Background_Black",          "\u001b[40m"},
            {"Background_Red",            "\u001b[41m"},
            {"Background_Green",          "\u001b[42m"},
            {"Background_Yellow",         "\u001b[43m"},
            {"Background_Blue",           "\u001b[44m"},
            {"Background_Magenta",        "\u001b[45m"},
            {"Background_Cyan",           "\u001b[46m"},
            {"Background_White",          "\u001b[47m"},
            {"Background_Bright_Black",   "\u001b[40;1m"},
            {"Background_Bright_Red",     "\u001b[41;1m"},
            {"Background_Bright_Green",   "\u001b[42;1m"},
            {"Background_Bright_Yellow",  "\u001b[43;1m"},
            {"Background_Bright_Blue",    "\u001b[44;1m"},
            {"Background_Bright_Magenta", "\u001b[45;1m"},
            {"Background_Bright_Cyan",    "\u001b[46;1m"},
            {"Background_Bright_White",   "\u001b[47;1m"}
    };

    static const std::unordered_map<std::string, std::string> decorationCode{
            {"Reset",     "\u001b[0m"},
            {"Bold",      "\u001b[1m"},
            {"Underline", "\u001b[4m"},
            {"Reversed",  "\u001b[7m"}
    };

    if (colorCode.find(color) == colorCode.end()) {
        std::string message{"Invalid color code. Let's try: "};
        for (const auto &[name, _]: colorCode) {
            message += name + " ";
        }
        throw std::invalid_argument(message);
    }

    if (decorationCode.find(decoration) == decorationCode.end()) {
        std::string message{"Invalid decoration code. Let's try: "};
        for (const auto &[name, _]: decorationCode) {
            message += name + " ";
        }
        throw std::invalid_argument(message);
    }

    std::cout << colorCode.at(color)
              << decorationCode.at(decoration)
              << text
              << colorCode.at("Reset")
              << std::flush;
}

char Utilities::generateLetter(const int &limit) {
    std::random_device seed;
    std::mt19937 generator{seed()};
    std::uniform_int_distribution<int> distribution{0, 25};
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[distribution(generator) % limit];
}

void Utilities::moveCursorUp(const int &n) {
    std::cout << "\u001b[" << n << "A";
}

void Utilities::moveCursorDown(const int &n) {
    std::cout << "\u001b[" << n << "B";
}

void Utilities::moveCursorRight(const int &n) {
    std::cout << "\u001b[" << n << "C";
}

void Utilities::moveCursorLeft(const int &n) {
    std::cout << "\u001b[" << n << "D";
}

void Utilities::clearScreenToEnd() {
    std::cout << "\u001b[0J";
}

void Utilities::clearScreenToBegin() {
    std::cout << "\u001b[1J";
}

void Utilities::clearScreen() {
    std::cout << "\u001b[2J";
}

void Utilities::clearLineToEnd() {
    std::cout << "\u001b[0K";
}

void Utilities::clearLineToBegin() {
    std::cout << "\u001b[1K";
}

void Utilities::clearLine() {
    std::cout << "\u001b[2K";
}

void Utilities::sleep(const int &milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int Utilities::generateNumber(const int &a, const int &b) {
    std::random_device seed;
    std::mt19937 generator{seed()};
    std::uniform_int_distribution<int> distribution{a, b};
    return distribution(generator);
}
