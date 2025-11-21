# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/HomePCB_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/HomePCB_autogen.dir/ParseCache.txt"
  "HomePCB_autogen"
  "lib/graphicsviews/CMakeFiles/PCBCursor_autogen.dir/AutogenUsed.txt"
  "lib/graphicsviews/CMakeFiles/PCBCursor_autogen.dir/ParseCache.txt"
  "lib/graphicsviews/PCBCursor_autogen"
  "lib/homepcb/CMakeFiles/PCBApplication_autogen.dir/AutogenUsed.txt"
  "lib/homepcb/CMakeFiles/PCBApplication_autogen.dir/ParseCache.txt"
  "lib/homepcb/PCBApplication_autogen"
  "lib/scene/CMakeFiles/PCBScene_autogen.dir/AutogenUsed.txt"
  "lib/scene/CMakeFiles/PCBScene_autogen.dir/ParseCache.txt"
  "lib/scene/PCBScene_autogen"
  "lib/shapes/CMakeFiles/PCBShapes_autogen.dir/AutogenUsed.txt"
  "lib/shapes/CMakeFiles/PCBShapes_autogen.dir/ParseCache.txt"
  "lib/shapes/PCBShapes_autogen"
  "lib/viewer/CMakeFiles/PCBViewer_autogen.dir/AutogenUsed.txt"
  "lib/viewer/CMakeFiles/PCBViewer_autogen.dir/ParseCache.txt"
  "lib/viewer/PCBViewer_autogen"
  "lib/widgets/CMakeFiles/PCBWidgets_autogen.dir/AutogenUsed.txt"
  "lib/widgets/CMakeFiles/PCBWidgets_autogen.dir/ParseCache.txt"
  "lib/widgets/PCBWidgets_autogen"
  )
endif()
