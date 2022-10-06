#pragma once

#include <list>
#include <utility>

#include "Element.hpp"
#include "Instruction.hpp"

namespace Gospel::Language::Semantic
{
    class Type;

    // Todo
    class Method : Element
    {
    public:
        /// Instructions of this method.
        std::list<Instruction> Instructions;

        /// The optional type where this method is declared. If null, then this method is a global method.
        Type* const DeclaredType;

        /// Whether this method is a static method or not.
        const bool IsStatic;

        /// Whether this method does not have the method body or not.
        const bool IsAbstract;

        /// Type information of parameters.
        const std::list<Type*> ParameterTypes;

        /// Type information of the return value. Being null means that this method does not have a return value.
        Type* const ReturnType;

        Method(std::string name, class Namespace* space, class Type* type,
                std::list<Type*> parameterTypes, Type* returnType,
                bool isStatic = false, bool isAbstract = false) :
            Element(std::move(name), space), DeclaredType(type),
            ParameterTypes(std::move(parameterTypes)), ReturnType(returnType),
            IsStatic(isStatic), IsAbstract(isAbstract)
        {}
    };
}