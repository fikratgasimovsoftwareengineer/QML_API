# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appjsonData_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appjsonData_autogen.dir/ParseCache.txt"
  "appjsonData_autogen"
  )
endif()
