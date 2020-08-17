#include "artdaq-core-demo/Overlays/FragmentType.hh"

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

demo::FragmentType demo::toFragmentType(std::string t_string)
{
	std::transform(t_string.begin(), t_string.end(), t_string.begin(), toupper);
	for (auto& it : names)
	{
		if (it.second == t_string) return it.first;
	}
	return FragmentType::INVALID;
}

std::string demo::fragmentTypeToString(FragmentType val)
{
	if (names.count(val))
	{
		return names.at(val);
	}

	return "INVALID/UNKNOWN";
}

std::map<artdaq::Fragment::type_t, std::string> demo::makeFragmentTypeMap()
{
	auto output = artdaq::Fragment::MakeSystemTypeMap();
	for (const auto& name : names)
	{
		output[name.first] = name.second;
	}
	return output;
}