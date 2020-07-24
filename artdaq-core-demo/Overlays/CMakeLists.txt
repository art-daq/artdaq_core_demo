cet_make(LIBRARIES
  ${ARTDAQ_DAQDATA}
  artdaq-core_Utilities
  ${CETLIB}
  ${CETLIB_EXCEPT}
  EXCLUDE
  ArtdaqDemo_fragmentNameHelper.cc
  )

  basic_plugin(ArtdaqDemo "fragmentNameHelper"
  artdaq-core_Data
  artdaq-core-demo_Overlays
  artdaq-core_Data_Artdaq_fragmentNameHelper
  MF_MessageLogger
)

install_headers()
install_source()
