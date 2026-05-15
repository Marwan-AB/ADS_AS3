project(Code_library)

set(HEADER_FILES
        graph.h
        dijkstra.h
        floyd.h
)

set(SOURCE_FILES
        graph.cpp
        dijkstra_floyd.cpp
)

add_library(Code_library STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(Code_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
