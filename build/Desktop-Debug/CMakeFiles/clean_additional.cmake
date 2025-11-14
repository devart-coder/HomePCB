# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/HomePCB_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/HomePCB_autogen.dir/ParseCache.txt"
  "HomePCB_autogen"
  )
endif()
