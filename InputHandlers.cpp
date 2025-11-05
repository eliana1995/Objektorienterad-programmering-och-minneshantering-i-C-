#include <InputHandlers.h>

int getIntFromUser(const std::string& prompt){
    int value;
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (ss >> value && ss.eof()) return value;
        std::cout << "Invalid input! Try again.\n";
    }
}

int getIntInRangeFromUser(int min, int max){
    int value;
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (ss >> value && ss.eof() && value >= min && value <= max){
            return value;
        } else { 
            std::cout << "Please enter an integer in the range " << min << " to " << max << ".\n";
        }
    }
}