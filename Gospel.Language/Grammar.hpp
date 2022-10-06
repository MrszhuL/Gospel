#pragma once

#include <unordered_map>
#include <string>

#include "Lexical/Keyword.hpp"
#include "Semantic/Intention.hpp"

namespace Gospel::Language
{
    // Todo
    class Grammar
    {
    private:
        /// Defined intentions.
        std::unordered_map<std::string, Semantic::Intention> Intentions;

    public:
        /**
         * @brief Get the intention definition with the specified name.
         * @param name Name of the intention.
         * @return Intention definition.
         */
        Semantic::Intention& operator[](const std::string& name)
        {
            return Intentions.try_emplace(name).first->second;
        }
    };
}