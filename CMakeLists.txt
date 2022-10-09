cmake_minimum_required(VERSION 3.23)
project(OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP main.cpp logging/Logger.cpp logging/Logger.hpp DAO/Dao.hpp DTO/Dto.cpp DTO/Dto.hpp market/Market.cpp market/Market.hpp market/MarketDao.cpp market/MarketDao.hpp market/MarketItemDTO.hpp util/Util.hpp)
