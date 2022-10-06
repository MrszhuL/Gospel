#pragma once

#include <functional>
#include <list>
#include <utility>

#include "Type.hpp"
#include "Method.hpp"

namespace Gospel::Language::Semantic
{
    // Todo
    class Intention
    {
    private:
        std::function<void(Type)> TypeBehavior;
        std::function<void(Method)> MethodBehavior;

    public:
        /// Set the behavior of this intention in a type context.
        Intention& SetBehaviorForType(std::function<void(Type)> behavior)
        {
            TypeBehavior = std::move(behavior);
            return *this;
        }

        /// Set the behavior of this intention in a method context.
        Intention& SetBehaviorForMethod(std::function<void(Method)> behavior)
        {
            MethodBehavior = std::move(behavior);
            return *this;
        }
    };
}