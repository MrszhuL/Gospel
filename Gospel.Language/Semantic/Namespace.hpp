#pragma once

#include <string>
#include <utility>
#include <unordered_map>
#include "Type.hpp"

namespace Gospel::Language::Semantic
{
    class Module;

    class Namespace
    {
    private:
        /// Types defined in this namespace.
        std::unordered_map<std::string, Type> Types;

        /// Outer namespace.
        Namespace* OuterNamespace {nullptr};

        /// Inner namespace.
        std::unordered_map<std::string, Namespace> InnerNamespaces;

    public:
        /// Name of this namespace.
        const std::string Name;

        /// The module where this namespace is declared.
        Module* const DeclaredModule;

        /// Outer namespace which contains this namespace.
        const decltype(OuterNamespace) Outer;

        /// Inner namespaces contained in this namespace.
        const decltype(InnerNamespaces)& Inner;

        explicit Namespace(std::string name, Module* module, Namespace* outer = nullptr) :
            Name(std::move(name)), DeclaredModule(module), Outer(OuterNamespace), Inner(InnerNamespaces), OuterNamespace(outer)
        {}

        Namespace(const Namespace&) = delete;

        Namespace(Namespace&& target)  noexcept :
            Name(target.Name), DeclaredModule(target.DeclaredModule),
            Outer(OuterNamespace), Inner(InnerNamespaces),
            OuterNamespace(target.OuterNamespace),
            InnerNamespaces(std::move(target.InnerNamespaces))
        {}

        /**
         * @brief Check whether this namespace contains a type with the specified name or not.
         * @param name Name of the type.
         * @param recursively
         *  If true, this method will try to look up the type in its outer namespace recursively;
         *  Otherwise this method will only try to look up this type in this namespace.
         * @return True if any type matches the specified name; otherwise false.
         */
        bool HasType(const std::string& name, bool recursively = true);

        /**
         * @brief Add a type to this namespace.
         * @param type Type to add to this namespace.
         * @return Type definition.
         */
        Type& AddType(Type&& type) noexcept(false);

        /**
         * @brief Get a type from this module.
         * @param name Name of the type.
         * @param recursively
         *  If true, this method will try to look up the type in its outer namespace recursively;
         *  Otherwise this method will only try to look up this type in this namespace.
         * @return Type definition.
         */
        Type& GetType(const std::string& name, bool recursively = true) noexcept(false);

        Namespace& AddNamespace(const std::string& name) noexcept(false);

        Namespace& GetNamespace(const std::string& name) noexcept(false);

        bool HasNamespace(const std::string& name);

        /// Get or create a sub namespace.
        Namespace& operator[](const std::string& name)
        {
            return InnerNamespaces.try_emplace(name, Namespace(name, DeclaredModule, this))
                .first->second;
        }
    };
}