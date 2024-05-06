# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AudioPlayer_autogen"
  "CMakeFiles\\AudioPlayer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AudioPlayer_autogen.dir\\ParseCache.txt"
  "TinyWidgetLibrary\\CMakeFiles\\TinyWidgetLibrary_autogen.dir\\AutogenUsed.txt"
  "TinyWidgetLibrary\\CMakeFiles\\TinyWidgetLibrary_autogen.dir\\ParseCache.txt"
  "TinyWidgetLibrary\\CMakeFiles\\test_autogen.dir\\AutogenUsed.txt"
  "TinyWidgetLibrary\\CMakeFiles\\test_autogen.dir\\ParseCache.txt"
  "TinyWidgetLibrary\\TinyWidgetLibrary_autogen"
  "TinyWidgetLibrary\\test_autogen"
  )
endif()
