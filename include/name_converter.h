#ifndef NAMECONVERTER_HPP
#define NAMECONVERTER_HPP

#include <string>

class NameConverter {
public:
    static std::string toSnakeCase(const std::string& s);
    static std::string toCamelCase(const std::string& s);
    static std::string toPascalCase(const std::string& s);
};

#endif // NAMECONVERTER_HPP
