#include "Namespace.hpp"

namespace Gospel::Language::Semantic
{
    Type& Namespace::AddType(Type &&type)
    {
        auto iterator = Types.find(type.Name);
        if (iterator != Types.end())
            throw std::exception("Type with the same name already exists.");
        return Types.emplace(type.Name, std::move(type)).first->second;
    }

    bool Namespace::HasType(const std::string& name, bool recursively)
    {
        auto iterator = Types.find(name);
        if (iterator == Types.end())
        {
            if (Outer == nullptr)
                return false;
            return Outer->HasType(name, recursively);
        }

        return true;
    }

    Type &Namespace::GetType(const std::string &name, bool recursively) noexcept(false)
    {
        auto iterator = Types.find(name);
        if (iterator == Types.end())
        {
            if (Outer == nullptr)
                throw std::exception("Can not find a type with the specified name.");
            return Outer->GetType(name, recursively);
        }

        return iterator->second;
    }

    Namespace &Namespace::AddNamespace(const std::string &name)
    {
        auto iterator = InnerNamespaces.find(name);
        if (iterator != InnerNamespaces.end())
            throw std::exception("Namespace with the specified name already exists.");
        return InnerNamespaces.emplace(name, Namespace(name, DeclaredModule, this))
                .first->second;
    }

    Namespace &Namespace::GetNamespace(const std::string &name)
    {
        auto iterator = InnerNamespaces.find(name);
        if (iterator == InnerNamespaces.end())
            throw std::exception("Namespace with the specified name already exists.");
        return InnerNamespaces.emplace(name, Namespace(name, DeclaredModule, this))
                .first->second;
    }

    bool Namespace::HasNamespace(const std::string &name)
    {
        return InnerNamespaces.contains(name);
    }


}