cet_make(LIBRARIES
  artdaq_core::artdaq-core_Utilities
  ${CETLIB}
  ${CETLIB_EXCEPT}
  EXCLUDE
  ArtdaqDemo_fragmentNameHelper.cc
  )

  basic_plugin(ArtdaqDemo "fragmentNameHelper"
  artdaq_core::artdaq-core_Data
  artdaq-core-demo_Overlays
  artdaq_core::artdaq-core_Data_Artdaq_fragmentNameHelper
  ${MF_MESSAGELOGGER}
)

install_headers()
install_source()
