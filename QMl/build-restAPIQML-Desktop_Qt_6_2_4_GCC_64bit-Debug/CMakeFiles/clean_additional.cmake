# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/apprestAPIQML_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/apprestAPIQML_autogen.dir/ParseCache.txt"
  "apprestAPIQML_autogen"
  )
endif()
