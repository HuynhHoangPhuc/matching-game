//
// Created by Phuc Huynh Hoang on 17/03/2022.
//

#ifndef MATCHINGGAME_UTILITIES_H
#define MATCHINGGAME_UTILITIES_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <random>
#include <chrono>
#include <thread>

struct Utilities {
    static void printColor(const std::string &text,
                           const std::string &color,
                           const std::string &decoration);

    static char generateLetter(const int &limit);

    static int generateNumber(const int &a, const int &b);

    static void moveCursorUp(const int &n);

    static void moveCursorDown(const int &n);

    static void moveCursorRight(const int &n);

    static void moveCursorLeft(const int &n);

    static void clearScreenToEnd();

    static void clearScreenToBegin();

    static void clearScreen();

    static void clearLineToEnd();

    static void clearLineToBegin();

    static void clearLine();

    static void sleep(const int &milliseconds);
};


#endif //MATCHINGGAME_UTILITIES_H
