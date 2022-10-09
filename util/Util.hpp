//
// Created by KirilliriK on 09.10.2022.
//

#ifndef OOP_UTIL_HPP
#define OOP_UTIL_HPP

#include <vector>
#include <string>

namespace Util {
    static std::vector<std::string> split(const std::string &s, const std::string &delimiter) {
        int posStart = 0;
        int posEnd;
        int delimiterLength = delimiter.length();

        std::string token;
        std::vector<std::string> res;

        while ((posEnd = s.find(delimiter, posStart)) != std::string::npos) {
            token = s.substr(posStart, posEnd - posStart);
            posStart = posEnd + delimiterLength;
            res.push_back(token);
        }

        res.push_back(s.substr(posStart));
        return res;
    }
}


#endif //OOP_UTIL_HPP