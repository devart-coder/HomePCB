add_library(
PCBCursor STATIC
    cursor/PCBCursor.h cursor/PCBCursor.cpp
    cursor/PCBSpotF.h cursor/PCBSpotF.cpp
)
target_include_directories(PCBCursor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/cursor
)
target_link_libraries(
    PCBCursor PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
)
