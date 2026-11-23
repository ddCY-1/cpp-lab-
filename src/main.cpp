#include "stats.hpp"
#include <cstdio>
#include <vector>

int main() {
    const std::vector<double> xs{2, 4, 4, 4, 5, 5, 7, 9};
    std::printf("n=%zu mean=%.3f stdev=%.3f\n", xs.size(), lab::mean(xs), lab::stdev(xs));
    for (double v : lab::normalize(xs)) std::printf("%.2f ", v);
    std::printf("\n");
}
