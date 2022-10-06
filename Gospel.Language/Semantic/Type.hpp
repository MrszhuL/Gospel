#pragma once

#include <list>

#include "Element.hpp"
#include "Visbility.hpp"

namespace Gospel::Language::Semantic
{
    class Method;

    class Type : public Element
    {
    public:
        using Element::Element;

        /// The type which this type inherits from.
        Type* const BaseType;

        /// Whether this type is an interface or not.
        const bool IsInterface;

        /// Whether this type is abstract or not.
        const bool IsAbstract;

        /**
         * @brief List of types declared in this type.
         * @details Types are still hold by the namespace; this list only provides a way to quickly find them.
         */
        std::list<Type*> NestedTypes;

        Type(std::string name, class Namespace* space, Type* base, bool isInterface = false, bool isAbstract = false)
                : Element(std::move(name), space), BaseType(base), IsInterface(isInterface), IsAbstract(isAbstract)
        {}
    };
}