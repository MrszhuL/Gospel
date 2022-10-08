#pragma once

#include <list>
#include <functional>

namespace Gospel::Language
{
    /**
     * @brief This concept defines a kind of machine instruction implementer.
     */
    template<typename TInstruction>
    concept Implementable = requires(std::list<std::byte> code)
    {
        std::is_convertible_v<decltype(TInstruction::Generator),
            std::function<void(TInstruction, std::list<std::byte>)>>;
    };
}