#include "DayOne.hpp"


int* ParseNumbers(std::string line) {
    int c1 = line.find('-');
    int c2 = line.find_last_of('-');
    int C = line.find(',');
    // std::cout << c1 << " " << c2 << " " << C << ": ";
    int *nums = (int *) malloc(4 * sizeof(int));
    nums[0] = ParseNumber(line.substr(0, c1));
    nums[1] = ParseNumber(line.substr(c1 + 1, C - c1));
    nums[2] = ParseNumber(line.substr(C + 1, c2 - C));
    nums[3] = ParseNumber(line.substr(c2 + 1));
    // std::cout << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3] << std::endl;
    return nums;
}

int ProblemSeven(std::string cleanup) {
    std::fstream cleanCamp;
    cleanCamp.open(cleanup, std::ios::in);
    std::string line;
    int count = 0;
    while(getline(cleanCamp, line)) {
        int *nums = ParseNumbers(line);
        if((nums[0] >= nums[2] && nums[1] <= nums[3]) || (nums[2] >= nums[0] && nums[3] <= nums[1])) {
            count++;
        }
    }
    return count;
}

int ProblemEight(std::string cleanup) {
    std::fstream cleanCamp;
    cleanCamp.open(cleanup, std::ios::in);
    std::string line;
    int count = 0;
    while(getline(cleanCamp, line)) {
        int *nums = ParseNumbers(line);
        if((nums[0] <= nums[3] && nums[1] >= nums[3]) || (nums[1] >= nums[2] && nums[0] <= nums[2]) || (nums[0] >= nums[2] && nums[1] <= nums[3]) || (nums[2] >= nums[0] && nums[3] <= nums[1])) {
            count++;
        }
    }
    return count;
}

/*
int main() {
    std::cout << ProblemSeven("CleanCamp.txt") << std::endl;
    std::cout << ProblemEight("CleanCamp.txt") << std::endl;
}
*/