#include "stats.hpp"
#include <cassert>
#include <cmath>
#include <cstdio>

static bool near(double a, double b) { return std::fabs(a - b) < 1e-9; }

int main() {
    const std::vector<double> xs{2, 4, 4, 4, 5, 5, 7, 9};
    assert(near(lab::mean(xs), 5.0));
    assert(near(lab::stdev(xs), 2.0));
    assert(near(lab::mean({}), 0.0));
    const auto n = lab::normalize(xs);
    assert(near(n.front(), 0.0) && near(n.back(), 1.0));
    const auto flat = lab::normalize(std::vector<double>{3, 3, 3});
    assert(flat[0] == 0.0 && flat[2] == 0.0);
    std::puts("all tests passed");
}
