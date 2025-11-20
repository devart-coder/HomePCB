add_library(
PCBViewer STATIC
PCBGraphicsViewer.h PCBGraphicsViewer.cpp
)
target_include_directories(
PCBViewer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(
    PCBViewer PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
)
