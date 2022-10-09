//
// Created by KirilliriK on 09.10.2022.
//

#include "Logger.hpp"

#include <iostream>

Logger::Logger(const std::string& name) {
    this->name = name;
    outputFile.open(name + ".txt");
}

Logger::~Logger() {
    outputFile.close();
}

void Logger::log(const std::string& log) {
    const std::string outputLog = "[" + name + "] " + log;

    std::cout << outputLog << std::endl;
    outputFile << outputLog << std::endl;
}

void Logger::logInput(const std::string &log) {
    const std::string outputLog = "[" + name + "] " + log;

    outputFile << log << std::endl;
}

Logger Logger::Fabric::build(const std::string &name) {
    return Logger(name);
}
