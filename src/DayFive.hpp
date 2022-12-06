#ifndef DAY_FIVE_H
#define DAY_FIVE_H

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <deque>
#include "DayOne.hpp"

struct direction {
    int quantity;
    int stackFrom;
    int stackTo;
};

std::vector<std::deque<char>> InitializeStacks(std::string stacks);

std::vector<direction> InitializeInstructions(std::string instructions);

void ProblemNine(std::vector<direction> instructions, std::vector<std::deque<char>> stacks);

void ProblemTen(std::vector<direction> instructions, std::vector<std::deque<char>> stacks);

int main();

#endif