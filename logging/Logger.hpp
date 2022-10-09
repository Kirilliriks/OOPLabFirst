//
// Created by KirilliriK on 09.10.2022.
//

#ifndef OOP_LOGGER_HPP
#define OOP_LOGGER_HPP

#include <string>
#include <fstream>

class Logger {
public:
    ~Logger();

    void log(const std::string &log);
    void logInput(const std::string &log);

    class Fabric {
    public:
        Logger build(const std::string &name);

        friend class Logger;
    };
protected:
    Logger(const std::string &name);

    std::string name;
    std::ofstream outputFile;
};


#endif //OOP_LOGGER_HPP
