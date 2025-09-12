add_executable(bm-sort_char-cmd bm_sort_char.cpp)
target_link_libraries(bm-sort_char-cmd sort_char benchmark::benchmark)
set_property(GLOBAL APPEND PROPERTY BENCHMARK_TARGETS bm-sort_char-cmd)
