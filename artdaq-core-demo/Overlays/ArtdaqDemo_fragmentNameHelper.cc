#include "artdaq-core-demo/Overlays/FragmentType.hh"
#include "artdaq-core/Data/FragmentNameHelper.hh"

#include "TRACE/tracemf.h"
#define TRACE_NAME "ArtdaqDemoFragmentNameHelper"

namespace artdaq {
/**
 * \brief ArtdaqDemoFragmentNameHelper extends ArtdaqFragmentNamingService.
 * This implementation uses artdaq-demo's SystemTypeMap and directly assigns names based on it
 */
class ArtdaqDemoFragmentNameHelper : public ArtdaqFragmentNameHelper
{
public:
	/**
	 * \brief DefaultArtdaqFragmentNamingService Destructor
	 */
	~ArtdaqDemoFragmentNameHelper() override = default;

	/**
	 * \brief ArtdaqDemoFragmentNameHelper Constructor
	 */
	ArtdaqDemoFragmentNameHelper(std::string unidentified_instance_name, std::vector<std::pair<artdaq::Fragment::type_t, std::string>> extraTypes);

private:
	ArtdaqDemoFragmentNameHelper(ArtdaqDemoFragmentNameHelper const&) = delete;
	ArtdaqDemoFragmentNameHelper(ArtdaqDemoFragmentNameHelper&&) = delete;
	ArtdaqDemoFragmentNameHelper& operator=(ArtdaqDemoFragmentNameHelper const&) = delete;
	ArtdaqDemoFragmentNameHelper& operator=(ArtdaqDemoFragmentNameHelper&&) = delete;
};

ArtdaqDemoFragmentNameHelper::ArtdaqDemoFragmentNameHelper(std::string unidentified_instance_name, std::vector<std::pair<artdaq::Fragment::type_t, std::string>> extraTypes)
    : ArtdaqFragmentNameHelper(unidentified_instance_name, extraTypes)
{
	TLOG(TLVL_DEBUG) << "ArtdaqDemoFragmentNameHelper CONSTRUCTOR START";
	SetBasicTypes(demo::makeFragmentTypeMap());
	TLOG(TLVL_DEBUG) << "ArtdaqDemoFragmentNameHelper CONSTRUCTOR END";
}
}  // namespace artdaq

DEFINE_ARTDAQ_FRAGMENT_NAME_HELPER(artdaq::ArtdaqDemoFragmentNameHelper)