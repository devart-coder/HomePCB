add_library(
    PCBApplication STATIC
    PCBApplication.h PCBApplication.cpp)
target_include_directories(PCBApplication PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
    PCBApplication PUBLIC
    PCBCursor
    PCBShapes
    PCBScene
    PCBWidgets
    PCBViewer
)
