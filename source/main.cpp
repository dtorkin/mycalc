#include "ShuntingYard.h"


int main() {
    try {
        std::string expression;
        std::getline(std::cin, expression);
        ShuntingYard mycalc;
        auto result = mycalc.calc(expression);
        std::cout << result << std::endl;
    }
    catch (std::exception& exception){
        std::cout << exception.what() << std::endl;
    }
    return 0;
}
