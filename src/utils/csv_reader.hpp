#pragma once
#include <functional>
#include <string>
#include <vector>

using CsvRow = std::vector<std::string_view>;

class CsvReaderUtils
{
// todo wrap below in full fileread function

public:
	static void
	getCsvRowValues(const std::string& row, char delimiter, std::function<void(CsvRow&)> action)
	{
		CsvRow valueVec;
		auto left = row.begin();
		for (auto it = left; it != row.end(); ++it)
		{
			if (*it == delimiter)
			{
				valueVec.emplace_back(&*left, it - left);
				left = it + 1;
			}
		}
		if (left != row.end())
			valueVec.emplace_back(&*left, row.end() - left);
		action(valueVec);
	}
};