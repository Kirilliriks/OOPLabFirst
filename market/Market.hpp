//
// Created by KirilliriK on 09.10.2022.
//

#ifndef OOP_MARKET_HPP
#define OOP_MARKET_HPP


#include "MarketDao.hpp"
#include "../logging/Logger.hpp"

class Market {
public:
    Market();
    ~Market() = default;

    void run();
    void selectAction();
    void viewAllItems();
    void viewItemById();
    void pushNewItem();
private:
    std::string handleInput(const std::string &inputText);

    Logger logger = Logger::Fabric().build("MarketLog");
    MarketDAO marketDao;
};


#endif //OOP_MARKET_HPP
