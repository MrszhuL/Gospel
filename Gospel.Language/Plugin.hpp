#pragma once

#include "Grammar.hpp"

namespace Gospel::Language
{
    /**
     * @brief Grammar rule set interface.
     * @details
     *  User should define their grammar rule set by implement this interface.
     */
    class Plugin
    {
    public:
        virtual void Modify(Grammar* grammar) = 0;
    };
}