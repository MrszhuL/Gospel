#pragma once

#include <list>
#include <hash_set>
#include "Task.hpp"
#include "Tasks/ParsingToken.hpp"

namespace Gospel::Builder
{
	class Controller
	{
	private:
		class Target
		{
		public:
			Task* Generator;
			std::hash_set<Task*> PreProcessors;
			std::hash_set<Task*> PostProcessors;
		};

		/// Registered targets.
		std::unordered_map<std::type_index, Target> Targets;

		/// Registered tasks.
		std::unordered_map<std::type_index, std::unique_ptr<Task>> Tasks;

	public:

		/// TaskType is designed to simply control the basic sequence of tasks.
		enum TaskType
		{
			/// This task is the main generator for the target content.
			Generator,
			/// This task is a pre-processor for the target content generation.
			PreProcessor,
			/// This task is a post-processor for the target content generation.
			PostProcessor
		};

		/**
		 * @brief Register a task to this controller.
		 * @tparam TTask Type of the task to register.
		 */
		template<typename TTask> requires IsTask<TTask>
		void RegisterTask(TaskType type = TaskType::Generator)
		{
			const std::vector<std::type_index>& targets = TTask::Targets;

			auto task = std::make_unique<TTask>();

			for (const auto& targetType : targets)
			{
				auto targetIterator = Targets.find(targetType);
				if (targetIterator == Targets.end())
				{
					targetIterator = Targets.emplace(targetType, Target()).first;
				}
				switch (type)
				{
					case Generator:
						targetIterator->second.Generator = task.get();
						break;
					case PreProcessor:
						targetIterator->second.PreProcessors = task.get();
						break;
					case PostProcessor:
						targetIterator->second.PostProcessors = task.get();
						break;
				}
			}

			Tasks.insert_or_assign(typeid(TTask), std::move(task));
		}

		/**
		 * @brief Unregister a task from this controller.
		 * @tparam TTask Type of the task to unregister.
		 */
		template<typename TTask> requires IsTask<TTask>
		void UnregisterTask(TaskType type = TaskType::Generator)
		{
			const std::vector<std::type_index>& targets = TTask::Targets;

			auto taskIterator = Tasks.template find(typeid(TTask));
			if (taskIterator == Tasks.end())
				return;

			for (const auto& targetType : targets)
			{
				auto targetIterator = Targets.find(targetType);
				if (targetIterator == Targets.end())
					continue;
				switch (type)
				{
					case Generator:
						if (targetIterator->second.Generator == taskIterator->second.get())
							targetIterator->second.Generator = nullptr;
						break;
					case PreProcessor:
						targetIterator->second.PreProcessors.erase(taskIterator->second.get());
						break;
					case PostProcessor:
						targetIterator->second.PostProcessors.erase(taskIterator->second.get());
						break;
				}
			}

			Tasks.erase(taskIterator);
		}
	};
}