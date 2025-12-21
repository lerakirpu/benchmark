#include <benchmark/benchmark.h>

// Итеративный факториал
long long factorial_iterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Рекурсивный факториал
long long factorial_recursive(int n) {
    if (n <= 1) return 1;
    return n * factorial_recursive(n - 1);
}

// Бенчмарк для итеративного метода
static void BM_Factorial_Iterative(benchmark::State& state) {
    int n = state.range(0);
    for (auto _ : state) {
        benchmark::DoNotOptimize(factorial_iterative(n));
    }
}

// Бенчмарк для рекурсивного метода
static void BM_Factorial_Recursive(benchmark::State& state) {
    int n = state.range(0);
    for (auto _ : state) {
        benchmark::DoNotOptimize(factorial_recursive(n));
    }
}

// Регистрируем бенчмарки для разных значений n
BENCHMARK(BM_Factorial_Iterative)->Arg(5)->Arg(10)->Arg(15)->Arg(20);
BENCHMARK(BM_Factorial_Recursive)->Arg(5)->Arg(10)->Arg(15)->Arg(20);

BENCHMARK_MAIN();