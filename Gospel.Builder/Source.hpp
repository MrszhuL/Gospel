#pragma once

#include <vector>
#include <list>

namespace Gospel::Builder
{
    template<typename TElement>
    class Source
    {
    protected:
        class Item
        {
        public:
            /// Whether this element should be ignored.
            bool Ignored;
            /// The element carried by this item.
            const TElement& Element;

            explicit Item(const TElement& element, bool ignored = false) : Element(element), Ignored(ignored)
            {}
        };

        std::vector<TElement> Sequence;

        std::list<Item> Workspace;

        int Index {0};

        bool Move(bool ignored)
        {

        }

    public:
        explicit Source(std::vector<TElement>&& data) : Sequence(std::move(data))
        {}

        bool IsValid()
        {
            return Index < Sequence.size();
        }

        const TElement& GetCurrent()
        {
            return Sequence[Index];
        }

        /**
         * @brief Save the current element into the workspace and move to the next one.
         */
        bool Push()
        {
            return Move(false);
        }

        /**
         * @brief Drop the current element and move to the next one.
         */
        bool Drop()
        {
            return Move(true);
        }

        /// Commit the whole workspace regardless of checkpoints.
        void Commit()
        {

        }

        /// Rollback to the latest checkpoint.
        void Rollback()
        {

        }

        /// Save the current consumed count as a new checkpoint.
        void AddCheckpoint()
        {

        }

        /// Remove the latest checkpoint.
        void RemoveCheckpoint()
        {

        }
    };
}