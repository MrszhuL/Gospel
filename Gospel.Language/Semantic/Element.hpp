#pragma once

#include "Visbility.hpp"

#include <list>
#include <utility>

namespace Gospel::Language::Semantic
{
    class Namespace;

    class Element
    {
    public:
        /// The namespace where this element is declared.
        Namespace* DeclaredNamespace;

        /// The visibility of this type.
        Visibility Visibility {Visibility::Private};

        /// The name of this element.
        const std::string Name;

        explicit Element(std::string name, class Namespace* space) :
                Name(std::move(name)), DeclaredNamespace(space)
        {}
    };
}