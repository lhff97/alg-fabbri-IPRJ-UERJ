add_library(sort_char
  sort_char.cpp
)

target_include_directories(sort_char PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(cmd)

if (alg_BUILD_TESTS)
  add_subdirectory(tests)
endif()

if (alg_BUILD_BENCHMARKS)
  add_subdirectory(benchmark)
endif()
