#ifndef DAY_ONE_H
#define DAY_ONE_H

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>


int ParseNumber(std::string number);

std::vector<int> toList(std::string inventoryFile);

int ProblemOne(std::vector<int> inventory);

int ProblemTwo(std::vector<int> inventory);

int main();

#endif