cet_make(LIBRARIES
  artdaq_core::artdaq-core_Utilities
  EXCLUDE
  ArtdaqDemo_fragmentNameHelper.cc
  )

  include(fragmentNameHelper)
  fragmentNameHelper(ArtdaqDemo LIBRARIES REG artdaq_core_demo::artdaq-core-demo_Overlays)


install_headers()
install_source()
