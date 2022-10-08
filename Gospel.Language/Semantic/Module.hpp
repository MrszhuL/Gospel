#pragma once

#include <string>
#include <unordered_map>
#include <optional>

#include "Type.hpp"
#include "Namespace.hpp"

namespace Gospel::Language::Semantic
{
    class Module : Namespace
    {
    public:
		explicit Module(std::string name) : Namespace(name, this, nullptr)
		{}
    };
}