#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
SET(CMAKE_IMPORT_FILE_VERSION 1)

# Compute the installation prefix relative to this file.
GET_FILENAME_COMPONENT(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
GET_FILENAME_COMPONENT(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)

# Import target "boost_date_time-mt-shared" for configuration "Release"
SET_PROPERTY(TARGET boost_date_time-mt-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_date_time-mt-shared PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_date_time-vc100-mt-1_47.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_date_time-vc100-mt-1_47.dll"
  )

# Import target "boost_date_time-mt-static" for configuration "Release"
SET_PROPERTY(TARGET boost_date_time-mt-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_date_time-mt-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_date_time-vc100-mt-1_47.lib"
  )

# Import target "boost_date_time-mt-shared-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_date_time-mt-shared-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_date_time-mt-shared-debug PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_date_time-vc100-mt-gd-1_47.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_date_time-vc100-mt-gd-1_47.dll"
  )

# Import target "boost_date_time-mt-static-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_date_time-mt-static-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_date_time-mt-static-debug PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_date_time-vc100-mt-gd-1_47.lib"
  )

# Import target "boost_thread-mt-shared" for configuration "Release"
SET_PROPERTY(TARGET boost_thread-mt-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_thread-mt-shared PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_thread-vc100-mt-1_47.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_thread-vc100-mt-1_47.dll"
  )

# Import target "boost_thread-mt-static" for configuration "Release"
SET_PROPERTY(TARGET boost_thread-mt-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_thread-mt-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_thread-vc100-mt-1_47.lib"
  )

# Import target "boost_thread-mt-shared-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_thread-mt-shared-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_thread-mt-shared-debug PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_thread-vc100-mt-gd-1_47.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_thread-vc100-mt-gd-1_47.dll"
  )

# Import target "boost_thread-mt-static-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_thread-mt-static-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_thread-mt-static-debug PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_thread-vc100-mt-gd-1_47.lib"
  )

# Import target "boost_system-mt-shared" for configuration "Release"
SET_PROPERTY(TARGET boost_system-mt-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_system-mt-shared PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_system-vc100-mt-1_47.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_system-vc100-mt-1_47.dll"
  )

# Import target "boost_system-mt-static" for configuration "Release"
SET_PROPERTY(TARGET boost_system-mt-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_system-mt-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_system-vc100-mt-1_47.lib"
  )

# Import target "boost_system-mt-shared-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_system-mt-shared-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_system-mt-shared-debug PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_system-vc100-mt-gd-1_47.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_system-vc100-mt-gd-1_47.dll"
  )

# Import target "boost_system-mt-static-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_system-mt-static-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_system-mt-static-debug PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_system-vc100-mt-gd-1_47.lib"
  )

# Import target "boost_filesystem-mt-shared" for configuration "Release"
SET_PROPERTY(TARGET boost_filesystem-mt-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_filesystem-mt-shared PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_filesystem-vc100-mt-1_47.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "boost_system-mt-shared"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_filesystem-vc100-mt-1_47.dll"
  )

# Import target "boost_filesystem-mt-static" for configuration "Release"
SET_PROPERTY(TARGET boost_filesystem-mt-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_filesystem-mt-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "boost_system-mt-static"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_filesystem-vc100-mt-1_47.lib"
  )

# Import target "boost_filesystem-mt-shared-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_filesystem-mt-shared-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_filesystem-mt-shared-debug PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_filesystem-vc100-mt-gd-1_47.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "boost_system-mt-shared-debug"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_filesystem-vc100-mt-gd-1_47.dll"
  )

# Import target "boost_filesystem-mt-static-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_filesystem-mt-static-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_filesystem-mt-static-debug PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "boost_system-mt-static-debug"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_filesystem-vc100-mt-gd-1_47.lib"
  )

# Import target "boost_iostreams-mt-shared" for configuration "Release"
SET_PROPERTY(TARGET boost_iostreams-mt-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_iostreams-mt-shared PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_iostreams-vc100-mt-1_47.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_iostreams-vc100-mt-1_47.dll"
  )

# Import target "boost_iostreams-mt-static" for configuration "Release"
SET_PROPERTY(TARGET boost_iostreams-mt-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_iostreams-mt-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_iostreams-vc100-mt-1_47.lib"
  )

# Import target "boost_iostreams-mt-shared-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_iostreams-mt-shared-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_iostreams-mt-shared-debug PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/boost_iostreams-vc100-mt-gd-1_47.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/boost_iostreams-vc100-mt-gd-1_47.dll"
  )

# Import target "boost_iostreams-mt-static-debug" for configuration "Release"
SET_PROPERTY(TARGET boost_iostreams-mt-static-debug APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
SET_TARGET_PROPERTIES(boost_iostreams-mt-static-debug PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libboost_iostreams-vc100-mt-gd-1_47.lib"
  )

# Cleanup temporary variables.
SET(_IMPORT_PREFIX)

# Commands beyond this point should not need to know the version.
SET(CMAKE_IMPORT_FILE_VERSION)
