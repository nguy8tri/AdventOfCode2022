#include "DayFive.hpp"

std::vector<std::deque<char>> InitializeStacks(std::string stacks) {
    std::fstream crates;
    crates.open(stacks, std::ios::in);

    std::vector<std::deque<char>> result;
    for(int i = 0; i < 9; i++) {
        std::deque<char> stack;
        result.push_back(stack);
    }

    for(int i = 0; i < 8; i++) {
        std::string s;
        getline(crates, s);
        for(int j = 0; j < 9; j++) {
            if(s.at(4 * j + 1) >= 'A' && s.at(4 * j + 1) <= 'Z') {
                result.at(j).push_back(s.at(4 * j + 1));
            }
        }
    }
    return result;
}

std::vector<direction> InitializeInstructions(std::string instructions) {
    std::fstream crates;
    crates.open(instructions, std::ios::in);
    std::string instruction;
    std::vector<direction> result;
    for(int i = 0; i < 10; i++) {
        getline(crates, instruction);
    }
    while(getline(crates, instruction)) {
        int c2 = instruction.find('f');
        int c4 = instruction.find('t');
        struct direction d = {ParseNumber(instruction.substr(5, c2 - 6)), 
                ParseNumber(instruction.substr(c2 + 5, c4 - c2 - 6)), 
                ParseNumber(instruction.substr(c4 + 3, instruction.size() - c4 - 3))};
        result.push_back(d);
    }

    return result;
}

void ProblemNine(std::vector<direction> instructions, std::vector<std::deque<char>> stacks) {
    for(struct direction instruction : instructions) {
        for(int i = 0; i < instruction.quantity; i++) {
            stacks.at(instruction.stackTo - 1).push_front(stacks.at(instruction.stackFrom - 1).front());
            // std::cout << stacks.at(instruction.stackFrom - 1).front();
            stacks.at(instruction.stackFrom - 1).pop_front();
        }
        // std::cout << std::endl;
    }
    for(int i = 0; i < 9; i++) {
        if(stacks.at(i).size() != 0) {
            std::cout << stacks.at(i).front();
        }
    } 
    std::cout << std::endl;
}


void ProblemTen(std::vector<direction> instructions, std::vector<std::deque<char>> stacks) {
    for(struct direction instruction : instructions) {
        for(int i = 0; i < instruction.quantity; i++) {
            stacks.at(instruction.stackTo - 1).push_front(stacks.at(instruction.stackFrom - 1).at(instruction.quantity - i - 1));
        }
        for(int i = 0; i < instruction.quantity; i++) {
            stacks.at(instruction.stackFrom - 1).pop_front();
        }
        // std::cout << std::endl;
    }
    for(int i = 0; i < 9; i++) {
        if(stacks.at(i).size() != 0) {
            std::cout << stacks.at(i).front();
        }
    } 
    std::cout << std::endl;
}

/*
int main() {
    std::vector<std::deque<char>> stacks = InitializeStacks("Crates.txt");
    std::vector<direction> instructions = InitializeInstructions("Crates.txt");
    ProblemNine(instructions, stacks);
    ProblemTen(instructions, stacks);
}
*/