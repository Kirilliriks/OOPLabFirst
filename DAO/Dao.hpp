//
// Created by KirilliriK on 09.10.2022.
//

#ifndef OOP_DAO_HPP
#define OOP_DAO_HPP

#include <string>
#include <fstream>
#include <map>

#include <iostream>

// Data Access Object
template<typename E>
class DAO {
public:
    DAO(const std::string &name) {
        this->name = name;
        dataFile.open(name + ".txt", std::ios::out | std::ios::in | std::ios::app);
    }

    ~DAO() {
        dataFile.close();
    }

    virtual void update(const std::string &key, E e)  = 0;

    virtual std::map<std::string, E> getAll()  = 0;
    virtual E getByKey(const std::string &key) = 0;

    // Renamed [delete -> clear] (The C++ standard highlights the "delete" keyword which cannot be used as a method name)
    virtual void clear() {
        dataFile.close();
        dataFile.open(name + ".txt", std::ofstream::out | std::ofstream::trunc);
    }
protected:
    std::string name;
    std::fstream dataFile;
};


#endif //OOP_DAO_HPP
