SET(PROJECT_NAME ModelChange)
SET(LIB_NAME model_change)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Og -g2 -ggdb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

project(${PROJECT_NAME} 
    LANGUAGES C CXX
    )

aux_source_directory(. MC_SRC)

SET(CMAKE_CXX_STANDARD 11)

include_directories(
        ./
        ../examples
)

add_executable(${PROJECT_NAME} 
    ${MC_SRC}
)

target_link_libraries(${PROJECT_NAME}
    tflm
    hello_world
    micro_speech
    person_detection
    -lpthread
    -lm)