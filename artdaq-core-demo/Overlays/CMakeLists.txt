cet_make_library(LIBRARY NAME Overlays
SOURCE	
AsciiFragment.cc
FragmentType.cc
ToyFragment.cc
UDPFragment.cc
LIBRARIES PUBLIC
  artdaq_core::artdaq-core_Utilities
  artdaq_core::artdaq-core_Data
  TRACE::TRACE
  )
  
  
include(ArtdaqCorePlugins)
cet_build_plugin(ArtdaqDemo artdaq::fragmentNameHelper LIBRARIES REG artdaq_core_demo::artdaq-core-demo_Overlays)


install_headers()
install_source()
