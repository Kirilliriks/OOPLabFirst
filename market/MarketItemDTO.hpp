//
// Created by KirilliriK on 09.10.2022.
//

#ifndef OOP_MARKETITEMDTO_HPP
#define OOP_MARKETITEMDTO_HPP


#include "../DTO/Dto.hpp"

#include <iostream>

class MarketItemDTO : public DTO {
public:
    enum Type {
        VEGETABLES,
        MEAT,
        FISH,
        DRINK,
        UNKNOWN
    };
    
    MarketItemDTO(const std::string &name, int type, int price) {
        this->name = name;
        switch (type) {
            case 0:
                this->type = VEGETABLES;
                break;
            case 1:
                this->type = MEAT;
                break;
            case 2:
                this->type = FISH;
                break;
            case 3:
                this->type = DRINK;
                break;
            default:
                this->type = UNKNOWN;
                break;
        }
        this->price = price;
    }

    std::string name;
    Type type;
    int price;
};


#endif //OOP_MARKETITEMDTO_HPP
