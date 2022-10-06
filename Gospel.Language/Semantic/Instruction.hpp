#pragma once

#include <functional>
#include <list>
#include <concepts>

namespace Gospel::Language::Semantic
{
    class Method;

    /**
     * @brief This concept defines a kind of machine instruction implementer.
     */
    template<typename TInstruction>
    concept Implementable = requires(Method method, std::list<std::byte> code)
    {
        std::is_convertible_v<decltype(TInstruction::Generator), std::function<void(Method, std::list<std::byte>)>>;
    };

    // Todo
    class Instruction
    {

    };
}