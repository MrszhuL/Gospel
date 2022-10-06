#pragma once

namespace Gospel::Language::Semantic
{
    enum Visibility
    {
        /// Visible to itself.
        Private = 0,
        /// Visible to itself and derived types.
        Protected = 1,
        /// Visible to all.
        Public = 2,
        /// Visible to all in the same module.
        Internal = 3,
        /// Visible to to itself and derived types in the same module.
        Family = 4
    };
}