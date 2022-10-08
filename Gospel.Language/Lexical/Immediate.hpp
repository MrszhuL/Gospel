#pragma once

#include "Token.hpp"

namespace Gospel::Language::Lexical
{
    class Immediate : public Token
    {
    protected:
        Immediate() = default;
    };

    class NumericImmediate : public Immediate
    {};

    class IntegerImmediate : public NumericImmediate
    {};

    class FloatImmediate : public NumericImmediate
    {};

    class TextualImmediate : public Immediate
    {};

    class CharacterImmediate : public Immediate
    {};
}