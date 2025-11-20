add_library(PCBScene STATIC PCBScene.h PCBScene.cpp)
target_include_directories(
    PCBScene PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/
)
target_link_libraries(
    PCBScene PUBLIC
    PCBCursor
    PCBShapes
)
