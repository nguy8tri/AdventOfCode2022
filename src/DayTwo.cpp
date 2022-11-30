#include <vector>
#include <iostream>
#include <string>
#include <fstream>

int Outcome(std::string strategy) {
    // std::cout << strategy << " ";
    strategy.at(2) = char(strategy.at(2) - 'X' + 'A');
    // std::cout << strategy << " ";
    if(strategy.at(0) == strategy.at(2)) {
        return 3 + strategy.at(2) - 'A' + 1;
    } else if(strategy.at(2) - strategy.at(0) == 1 || strategy.at(2) - strategy.at(0) == - 2) {
        return 6 + strategy.at(2) - 'A' + 1;
    } else {
        return strategy.at(2) - 'A' + 1;
    }
}

std::vector<int> Outcomes(std::string strategies) {
    std::fstream strats;
    strats.open(strategies, std::ios::in);
    std::vector<int> result;
    if(strats.is_open()) {
        // std::cout << "Hello World!";
        std::string strategy;
        while(std::getline(strats, strategy)) {
            // std::cout << number << std::endl;
            result.push_back(Outcome(strategy));
            // std::cout << result.at(result.size() - 1) << std::endl;
        }
    }
    strats.close();
    return result;
}


int ProblemThree(std::vector<int> outcomes) {
    int sum = 0;
    for(int outcome : outcomes) {
        sum += outcome;
    }
    return sum;
}

int Outcome2(std::string strategy) {
    std::cout << strategy << " ";
    if(strategy.at(2) == 'X') {
        return strategy.at(0) - 'A' != 0 ? strategy.at(0) - 'A' : 3;
    } else if(strategy.at(2) == 'Y') {
        return 3 + strategy.at(0) - 'A' + 1;
    } else {
        return 6 + (strategy.at(0) - 'A' + 2 != 4 ? strategy.at(0) - 'A' + 2 : 1);
    }
}

std::vector<int> Outcomes2(std::string strategies) {
    std::fstream strats;
    strats.open(strategies, std::ios::in);
    std::vector<int> result;
    if(strats.is_open()) {
        // std::cout << "Hello World!";
        std::string strategy;
        while(std::getline(strats, strategy)) {
            // std::cout << number << std::endl;
            result.push_back(Outcome2(strategy));
            std::cout << result.at(result.size() - 1) << std::endl;
        }
    }
    strats.close();
    return result;
}

int ProblemFour(std::vector<int> outcomes) {
    int sum = 0;
    for(int outcome : outcomes) {
        sum += outcome;
    }
    return sum;
}

/*
int main() {
    std::vector<int> outcomes = Outcomes("RPSStrategy.txt");
    std::vector<int> outcomes2 = Outcomes2("RPSStrategy.txt");
    std::cout << ProblemThree(outcomes) << std::endl;
    std::cout << ProblemFour(outcomes2) << std::endl;
}
*/