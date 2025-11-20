add_library(
PCBShapes STATIC
line/PCBLine.h line/PCBLine.cpp
line/settings/PCBLineSettings.h line/settings/PCBLineSettings.cpp
)
target_include_directories(
    PCBShapes PUBLIC RECURCIVE
    ${CMAKE_CURRENT_SOURCE_DIR}/line
    ${CMAKE_CURRENT_SOURCE_DIR}/line/settings
)
target_link_libraries(
    PCBShapes PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
)
