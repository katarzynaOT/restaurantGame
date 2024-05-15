# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\restaurantGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\restaurantGame_autogen.dir\\ParseCache.txt"
  "restaurantGame_autogen"
  )
endif()
