#ifndef artdaq_demo_Overlays_FragmentType_hh
#define artdaq_demo_Overlays_FragmentType_hh
#include "artdaq-core/Data/Fragment.hh"
#include <unordered_map>

namespace demo {

/**
 * \brief Implementation details namespace
 */
namespace detail {
/**
 * \brief User type codes defined by artdaq_core_demo
 */
enum FragmentType : artdaq::Fragment::type_t
{
	MISSED = artdaq::Fragment::FirstUserFragmentType,
	TOY1 = artdaq::Fragment::FirstUserFragmentType + 1,
	TOY2 = artdaq::Fragment::FirstUserFragmentType + 2,
	ASCII = artdaq::Fragment::FirstUserFragmentType + 3,
	UDP = artdaq::Fragment::FirstUserFragmentType + 4,
	INVALID  // Should always be last.
};

// Safety check.
static_assert(artdaq::Fragment::isUserFragmentType(FragmentType::INVALID - 1), "Too many user-defined fragments!");
}  // namespace detail

using detail::FragmentType;

/**
 * \brief List of names (in the order defined below) of the User types defined in artdaq_core_demo
 */
std::unordered_map<FragmentType, std::string> const names{
	{FragmentType::MISSED, "MISSED"}, 
	{FragmentType::TOY1, "TOY1"}, 
	{FragmentType::TOY2, "TOY2"}, 
	{FragmentType::ASCII, "ASCII"}, 
	{FragmentType::UDP, "UDP"},
    {FragmentType::INVALID, "UNKNOWN"}};

/**
 * \brief Lookup the type code for a fragment by its string name
 * \param t_string Name of the Fragment type to lookup
 * \return artdaq::Fragment::type_t corresponding to string, or INVALID if not found
 */
FragmentType toFragmentType(std::string t_string);

/**
 * \brief Look up the name of the given FragmentType
 * \param val FragmentType to look up
 * \return Name of the given type (from the names vector)
 */
std::string fragmentTypeToString(FragmentType val);

/**
 * \brief Create a list of all Fragment types defined by this package, in the format that RawInput expects
 * \return A list of all Fragment types defined by this package, in the format that RawInput expects
 */
std::map<artdaq::Fragment::type_t, std::string> makeFragmentTypeMap();
}  // namespace demo
#endif /* artdaq_demo_Overlays_FragmentType_hh */
