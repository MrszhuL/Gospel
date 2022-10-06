#pragma once

#include <memory>

namespace Gospel::Language
{
    template<typename TObject> using Pointer = std::shared_ptr<TObject>;
}