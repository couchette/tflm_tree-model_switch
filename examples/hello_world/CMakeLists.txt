SET(PROJECT_NAME HelloWorld)
SET(LIB_NAME hello_world)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Og -g2 -ggdb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

project(${PROJECT_NAME} 
    LANGUAGES C CXX
    )

aux_source_directory(. HW_SRC)
aux_source_directory(./models HW_SRC)

SET(CMAKE_CXX_STANDARD 11)

include_directories(
        ./
        ../../
        ../../third_party/flatbuffers/include
        ../../third_party/gemmlowp
        ../../third_party/ruy
        ../../third_party/kissfft
)

add_executable(${PROJECT_NAME} 
    ${HW_SRC}
)

target_link_libraries(${PROJECT_NAME}
    tflm
    -lpthread
    -lm)