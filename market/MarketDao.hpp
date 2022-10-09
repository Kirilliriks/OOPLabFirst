//
// Created by KirilliriK on 09.10.2022.
//

#ifndef OOP_MARKETDAO_HPP
#define OOP_MARKETDAO_HPP

#include "../DAO/Dao.hpp"
#include "MarketItemDTO.hpp"

class MarketDAO : public DAO<MarketItemDTO> {
public:
    MarketDAO();

    ~MarketDAO() = default;

    void update(const std::string &key, MarketItemDTO dto) override;

    std::map<std::string, MarketItemDTO> getAll() override;
    MarketItemDTO getByKey(const std::string &key) override;

    std::string DTOToLine(const MarketItemDTO &dto);
private:
    MarketItemDTO lineToDTO(std::vector<std::string> values);
};


#endif //OOP_MARKETDAO_HPP
