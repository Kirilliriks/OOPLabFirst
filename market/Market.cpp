//
// Created by KirilliriK on 09.10.2022.
//

#include "Market.hpp"

#include <iostream>
#include <string>

Market::Market() {
    logger.log("Initialize complete!");
}

void Market::run() {
    logger.log("Welcome to Tiny-Market!");
    logger.log("");
    for (;;) {
        selectAction();
    }
}

void Market::selectAction() {
    std::string answer = handleInput("Entry your action-ID (0 - view all items, 1 - view item by id, 2 - push new item, 3 - exit)");

    try {
        switch (std::stoi(answer)) {
            case 0:
                viewAllItems();
                break;
            case 1:
                viewItemById();
                break;
            case 2:
                pushNewItem();
                break;
            case 3:
                exit(0);
            default:
                throw std::invalid_argument("");
        }
    } catch (std::invalid_argument &error) {
        logger.log("Wrong action number: " + answer);
    }
    selectAction();
}

void Market::viewAllItems() {
    const auto items = marketDao.getAll();
    for (const auto &pair : items) {
        const MarketItemDTO item = pair.second;
        logger.log(pair.first + ":" + marketDao.DTOToLine(item));
    }
}

void Market::viewItemById() {
    const std::string id = handleInput("Entry item id: ");

    const auto items = marketDao.getAll();
    for (const auto &pair : items) {
        if (pair.first != id) continue;
        const MarketItemDTO item = pair.second;
        logger.log(id + ":" + marketDao.DTOToLine(item));
    }
}

void Market::pushNewItem() {
    std::string id = handleInput("Entry new item id: ");
    std::string name = handleInput("Entry new item name: ");

    std::string type = handleInput("Entry new item Type[0 = VEGETABLES, 1 = MEAT, 2 = FISH, 3 = DRINK]: ");
    int intType;
    try {
        intType = std::stoi(type);

        if (intType < 0 || intType > 3) {
            throw std::invalid_argument("");
        }

    } catch (std::invalid_argument &error) {
        logger.log("Wrong type number: " + type);
        return;
    }

    std::string price = handleInput("Entry new item price: ");
    int intPrice;
    try {
        intPrice = std::stoi(price);
    } catch (std::invalid_argument &error) {
        logger.log("Wrong price number: " + price);
        return;
    }

    MarketItemDTO dto(name, intType, intPrice);
    marketDao.update(id, dto);
}

std::string Market::handleInput(const std::string &inputText) {
    logger.log(inputText);
    std::string input;
    std::cin >> input;
    logger.logInput(input);
    return input;
}
