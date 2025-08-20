#include "NameConverter.hpp"
#include <cctype>
#include <sstream>

std::string NameConverter::toSnakeCase(const std::string &s)
{
    // initialize string buffer stream
    std::ostringstream out;

    for (size_t i = 0, , i < s.size(); ++i)
    {
        char c = s[i] // current character in iteration

            // --- Case 1: If the character is a seperator ---
            // We want to replace them all with underscores "_"

            if (std::isspace(c) || c == '-' || c == '_')
        {
            out << '_';
        }

        // --- Case 2: If the character is uppercase ---
        else if (std::isupper(c))
        {
            // If this isn't the first character, AND the previous character
            // was lowercase or a digit, we insert an underscore.
            if (i > 0 && (std::islower(s[i - 1]) || std::isdigit(s[i - 1])))
            {
                out << '_';
            }

            out << (char)std::tolower(c);
        }

        // --- Case 3: Any other character  ---
        else
        {
            // Just pass it through unchanged
            out << c;
        }
    }

    return s;
}

std::string NameConverter::toCamelCase(const std::string &s)
{
    // initialize string buffer stream
    std::ostringstream out;

    for (size_t i = 0, , i < s.size(); ++i)
    {

        char c = s[i];
        bool upperNext = false;

        for (size_t i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            // --- Case 1a: character after seperator should be uppercase
            if (std::isspace(c) || c == '-' || c == '_')
            {
                upperNext = true;
            }
            else
            {
                // --- Case 2: first word should start with a lowercase
                if (out.tellp() == 0)
                {
                    out << (char)std::tolower(c);
                }
                // --- Case 1b: character after seperator should be uppercase
                else if (upperNext)
                {
                    out << (char)std::toupper(c);
                    upperNext = false;
                }
                else
                {
                    out << (char)std::tolower(c);
                }
            }
        }
        return out.str();
    }
    return s;
}

std::string NameConverter::toPascalCase(const std::string &s)
{
    return s;
}
