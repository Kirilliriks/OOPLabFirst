#include "market/Market.hpp"

#include <iostream>

int main() {
    try {
        Market market;
        market.run();
    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
    }
    return 0;
}
