#include "stats.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>

namespace lab {

double mean(std::span<const double> xs) {
    if (xs.empty()) return 0.0;
    return std::accumulate(xs.begin(), xs.end(), 0.0) / static_cast<double>(xs.size());
}

double stdev(std::span<const double> xs) {
    if (xs.size() < 2) return 0.0;
    const double m = mean(xs);
    double acc = 0.0;
    for (double x : xs) acc += (x - m) * (x - m);
    return std::sqrt(acc / static_cast<double>(xs.size()));
}

std::vector<double> normalize(std::span<const double> xs) {
    std::vector<double> out(xs.begin(), xs.end());
    if (out.empty()) return out;
    const auto [lo, hi] = std::minmax_element(out.begin(), out.end());
    // 注意：lo/hi 是指向 out 内部的迭代器，必须先把值拷出来再改写 out
    const double lo_v = *lo, hi_v = *hi;
    const double span = hi_v - lo_v;
    if (span == 0.0) { std::ranges::fill(out, 0.0); return out; }
    for (double& x : out) x = (x - lo_v) / span;
    return out;
}

}
