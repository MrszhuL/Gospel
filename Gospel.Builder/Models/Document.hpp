#pragma once

#include <list>
#include <string>

namespace Gospel::Builder
{
	class Document
	{
	public:
		/// File name of this document file.
		std::string Name;

		/// Relative path of this document file.
		std::string Path;

		/// Content of this document.
		std::list<std::string> Content;
	};
}