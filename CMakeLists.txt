SET(PROJECT_NAME tflm)
SET(LIB_NAME tflm)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Og -g2 -ggdb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

project(${PROJECT_NAME} 
    LANGUAGES C CXX
    )

aux_source_directory(tensorflow/lite/c COMMON_SRC)  
aux_source_directory(tensorflow/lite/core/api COMMON_SRC)
aux_source_directory(tensorflow/lite/core/c COMMON_SRC)  
aux_source_directory(tensorflow/lite/experimental/microfrontend/lib COMMON_SRC)
aux_source_directory(tensorflow/lite/kernels COMMON_SRC)
aux_source_directory(tensorflow/lite/kernels/optimized COMMON_SRC)
aux_source_directory("tensorflow/lite/kernels/internal" COMMON_SRC)
aux_source_directory("tensorflow/lite/kernels/internal/reference" COMMON_SRC)
aux_source_directory("tensorflow/lite/kernels/internal/reference/integer_ops" COMMON_SRC)
aux_source_directory(tensorflow/lite/micro COMMON_SRC)
aux_source_directory(tensorflow/lite/micro/arena_allocator COMMON_SRC)
aux_source_directory(tensorflow/lite/micro/kernels COMMON_SRC)
aux_source_directory(tensorflow/lite/micro/memory_planner COMMON_SRC)
aux_source_directory(tensorflow/lite/micro/models COMMON_SRC)
aux_source_directory(tensorflow/lite/micro/tflite_bridge COMMON_SRC)
aux_source_directory(tensorflow/lite/schema/ COMMON_SRC)

SET(CMAKE_CXX_STANDARD 11)

include_directories(
        ./
        third_party/flatbuffers/include
        third_party/gemmlowp
        third_party/ruy
        third_party/kissfft)

add_library(${LIB_NAME} SHARED
${COMMON_SRC}
)

target_link_libraries(${LIB_NAME}
    -lpthread
    -lm)

add_subdirectory(examples/hello_world)
add_subdirectory(examples/micro_speech)
add_subdirectory(examples/person_detection)
add_subdirectory(src)
  