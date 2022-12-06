#include "DayOne.hpp"


int ParseNumber(std::string number) {
    // std::cout << std::endl;
    if(number.at(0) > '9' || number.at(0) < '0') {
        // std::cout << number.at(0) << " ";
        return -1;
    }
    int sum = 0;
    int length = number.length();
    if(number.at(number.length() - 1) > '9' || number.at(number.length() - 1) < '0') {
        length--;
    }
    // std::cout << number << ": ";
    for(int i = 0; i < length; i++) {
        // std::cout << int(number.at(i) - '0') * int(pow(10, length - i - 1)) << " ";
        sum += int(number.at(i) - '0') * int(pow(10, length - i - 1));
    }
    // std::cout << sum << std::endl;
    // std::cout << sum << std::endl;
    return sum;
}

std::vector<int> toList(std::string inventoryFile) {
    std::fstream inventory;
    inventory.open(inventoryFile, std::ios::in);
    std::vector<int> result;
    if(inventory.is_open()) {
        // std::cout << "Hello World!";
        std::string number;
        int sum = 0;
        while(std::getline(inventory, number)) {
            // std::cout << number << std::endl;
            int num = ParseNumber(number);
            if(num == -1) {
                result.push_back(sum);
                sum = 0;
            } else {
                sum += num;
            }
        }
    }
    inventory.close();
    return result;
}

int ProblemOne(std::vector<int> inventory) {
    int max = 0;
    for(int i = 0; i < int(inventory.size()); i++) {
        if(inventory.at(i) > max) {
            max = inventory.at(i);
        }
    }
    return max;
}

int ProblemTwo(std::vector<int> inventory) {
    std::sort(inventory.begin(), inventory.end());
    int result = 0;
    for(int i = inventory.size() - 1; i > int(inventory.size()) - 4; i--) {
        result += inventory.at(i);
    }
    return result;
}
/*
int main() {
    std::vector<int> inventory = toList("ElfInventory.txt");
    std::cout << ProblemOne(inventory) << std::endl;
    std::cout << ProblemTwo(inventory) << std::endl;
}
*/