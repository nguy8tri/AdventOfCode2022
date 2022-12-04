#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>


int ProblemSix(std::string rucksack) {
    std::fstream rs;
    rs.open(rucksack, std::ios::in);
    std::vector<char> result;
    if(rs.is_open()) {
        std::string ruck1;
        while(std::getline(rs, ruck1)) {
            std::string ruck2;
            std::getline(rs, ruck2);
            std::string ruck3;
            std::getline(rs, ruck3);
            std::set<char> items;
            std::set<char> items2;
            // std::cout << ruck << std::endl;
            for(int i = 0; i < int(ruck1.size()); i++) {
                items.insert(ruck1.at(i));
            }
            for(int i = 0; i < int(ruck2.size()); i++) {
                if(items.find(ruck2.at(i)) != items.end()) {
                    items2.insert(ruck2.at(i));
                }
            }
            for(int i = 0; i < int(ruck3.size()); i++) {
                if(items2.find(ruck3.at(i)) != items2.end()) {
                    result.push_back(ruck3.at(i));
                    items2.erase(ruck3.at(i));
                }
            }
        } 
    }
    // std::cout << result.size() << std::endl;
    int sum = 0;
    for(char c : result) {
        // std::cout << c << " ";
        if(c >= 'a') {
            sum += c - 'a' + 1;
        } else {
            sum += c - 'A' + 27;
        }
    }
    // std::cout << std::endl;
    return sum;
}

int ProblemFive(std::string rucksack) {
    std::fstream rs;
    rs.open(rucksack, std::ios::in);
    std::vector<char> result;
    if(rs.is_open()) {
        std::string ruck;
        while(std::getline(rs, ruck)) {
            int length = ruck.size() / 2;
            std::set<char> items;
            // std::cout << ruck << std::endl;
            for(int i = 0; i < length; i++) {
                items.insert(ruck.at(i));
            }
            for(int i = length; i < int(ruck.size()); i++) {
                if(items.find(ruck.at(i)) != items.end()) {
                    result.push_back(ruck.at(i));
                    items.erase(ruck.at(i));
                }
            }
        }
    }
    // std::cout << result.size() << std::endl;
    int sum = 0;
    for(char c : result) {
        // std::cout << c << " ";
        if(c >= 'a') {
            sum += c - 'a' + 1;
        } else {
            sum += c - 'A' + 27;
        }
    }
    // std::cout << std::endl;
    return sum;
}



int main()  {
    std::cout << ProblemFive("Rucksack.txt") << std::endl;
    std::cout << ProblemSix("Rucksack.txt") << std::endl;
}