#pragma once
#include <span>
#include <vector>

namespace lab {
// 均值；空输入返回 0
double mean(std::span<const double> xs);
// 总体标准差
double stdev(std::span<const double> xs);
// 归一化到 [0,1]；全等输入返回全 0
std::vector<double> normalize(std::span<const double> xs);
}
