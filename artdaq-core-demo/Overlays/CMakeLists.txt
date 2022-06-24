cet_make(LIBRARIES PUBLIC
  artdaq_core::artdaq-core_Utilities
  artdaq_core::artdaq-core_Data
  TRACE::TRACE
  EXCLUDE
  ArtdaqDemo_fragmentNameHelper.cc
  )
  
  
include(ArtdaqCorePlugins)
cet_build_plugin(ArtdaqDemo artdaq::fragmentNameHelper LIBRARIES REG artdaq_core_demo::artdaq-core-demo_Overlays)


install_headers()
install_source()
