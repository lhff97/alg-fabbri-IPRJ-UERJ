#include <benchmark/benchmark.h>
#include "sort_char.h"
#include <vector>
#include <algorithm>
#include <random>
#include <string>

// Fills a string with random characters.
static void fill_random_string(std::string& str, int size) {
    str.resize(size);
    if (size == 0) return;
    // Seed with a fixed value for reproducibility
    static std::mt19937 gen(42);
    std::uniform_int_distribution<> distrib(0, 255);

    for (int i = 0; i < size; ++i)
        str[i] = static_cast<char>(distrib(gen));
}

class sort_char_fixture : public benchmark::Fixture {
public:
  void SetUp(const ::benchmark::State& state) {
    int size = state.range(0);
    fill_random_string(str, size);
  }

  std::string str;
};

BENCHMARK_DEFINE_F(sort_char_fixture, BM_sort_char)(benchmark::State& state) {
  for (auto _ : state) {
    // The sort_char function modifies the string in-place.
    // To have the same input for each iteration, we need to reset it.
    state.PauseTiming();
    std::string temp_str = str;
    state.ResumeTiming();
    sort_char(&temp_str[0]);
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
}

BENCHMARK_REGISTER_F(sort_char_fixture, BM_sort_char)->Range(8, 8<<10);

BENCHMARK_MAIN();
