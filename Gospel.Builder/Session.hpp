#pragma once

#include <any>
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <list>
#include <string>
#include "Models/Document.hpp"
#include "../Gospel.Language/Gospel.Laungage.hpp"

namespace Gospel::Builder
{
	class Controller;

	/// A session manages the data needed to compile a module.
	class Session
	{
	private:
		std::unordered_map<std::type_index, std::any> Data;

		Controller* const Controller;

	public:
		/// The module which this session is trying to build.
		const std::shared_ptr<Language::Semantic::Module> Module;

		/// All documents contained in this module.
		std::list<Document> Documents;

		explicit Session(const std::string& name, class Controller* controller) :
				Controller(controller), Module(std::make_shared<Language::Semantic::Module>(name))
		{}

		/// Get a content from this session.
		template<typename TContent>
		TContent* Get()
		{
			auto iterator = Data.find(typeid(TContent));
			if (iterator == Data.end())
				return nullptr;
			return std::any_cast<TContent*>(iterator->second);
		}

		/// Set a content to this session.
		template<typename TContent>
		void Set(TContent&& content)
		{
			Data.insert_or_assign(typeid(TContent), std::make_any<TContent>(std::forward<TContent>(content)));
		}
	};
}