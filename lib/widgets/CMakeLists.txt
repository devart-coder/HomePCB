add_library(
PCBWidgets STATIC
gcode/PCBGCodeWidget.h gcode/PCBGCodeWidget.cpp
tools/PCBCursorToolbar.h tools/PCBCursorToolbar.cpp
)
target_include_directories(
    PCBWidgets PUBLIC
    gcode
    tools
)
target_link_libraries(
    PCBWidgets PUBLIC
    PCBCursor
    PCBShapes
)
