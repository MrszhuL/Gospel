#pragma once

#include <concepts>
#include <typeindex>
#include <vector>

#include "Session.hpp"

namespace Gospel::Builder
{
	class Task;

	template<typename TTask>
	concept IsTask = requires
	{
		/// A task must have a default constructor.
		{new TTask()} -> std::convertible_to<Task*>;
		/// A task must have a const list of input contexts.
		{TTask::Targets} -> std::convertible_to<std::vector<std::type_index>>;
	};

	class Task
	{
	public:
		virtual void Execute(Session& session) = 0;

		virtual ~Task() = default;
	};

	template<typename... TargetTypes>
	class TaskFor : public Task
	{
	public:
		static std::vector<std::type_index> Targets;
	};

	template<typename... TargetTypes>
	std::vector<std::type_index> TaskFor<TargetTypes...>::Targets = {typeid(TargetTypes)...};

	class IntTask : public TaskFor<int>
	{
	public:
		void Execute(Session& session) override
		{

		}
	};
}