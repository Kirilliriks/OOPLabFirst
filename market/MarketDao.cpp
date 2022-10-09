//
// Created by KirilliriK on 09.10.2022.
//

#include "MarketDao.hpp"

#include <vector>

#include "../Util/Util.hpp"

MarketDAO::MarketDAO() : DAO("Market") {

}

void MarketDAO::update(const std::string &key, MarketItemDTO dto) {
    const std::string data = key + ':' + DTOToLine(dto);

    dataFile.clear();
    dataFile.seekp(std::ios::end);
    dataFile << data << std::endl;
}

std::map<std::string, MarketItemDTO> MarketDAO::getAll() {
    std::map<std::string, MarketItemDTO> map;

    std::string line;

    dataFile.clear();
    dataFile.seekg(std::ios::beg);
    while(std::getline(dataFile, line)) {
        const std::vector<std::string> values = Util::split(line, ":");
        map.insert(std::pair{values[0], lineToDTO(values)});
    }

    return map;
}

MarketItemDTO MarketDAO::getByKey(const std::string &key) {
    std::string line;

    dataFile.clear();
    dataFile.seekg(std::ios::beg);
    while(std::getline(dataFile, line)) {
        const std::vector<std::string> values = Util::split(line, ":");
        if (values[0] == key) return lineToDTO(values);
    }
    return MarketItemDTO("null", MarketItemDTO::Type::UNKNOWN, -1);
}

std::string MarketDAO::DTOToLine(const MarketItemDTO &dto) {
    return dto.name + ':' + std::to_string(dto.price) + ':' + std::to_string(dto.type);
}

MarketItemDTO MarketDAO::lineToDTO(std::vector<std::string> values) {
    if (values.size() <= 1) {
        return MarketItemDTO("null", 4, -1);
    }

    int type;
    try {
        type = std::stoi(values[2]);
    } catch (std::invalid_argument &error) {
        type = 4;
    }

    int price;
    try {
        price = std::stoi(values[3]);
    } catch (std::invalid_argument &error) {
        price = -1;
    }
    return MarketItemDTO(values[1], type, price);
}
