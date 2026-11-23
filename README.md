# cpp-lab

C++20 练习场：每学一块内容就落一个带测试的小模块。

## 构建与测试

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build -j4
ctest --test-dir build --output-on-failure
./build/demo
```

## 结构

```
src/      库代码（stats 统计工具：mean / stdev / normalize）
tests/    单测（目前用 assert，后续换 GoogleTest 或 Catch2）
```

## 已知坑记录

- `normalize()` 里 `std::minmax_element` 返回的是指向 `out` 内部的迭代器。
  如果一边解引用 `*lo`/`*hi` 一边改写 `out`，值会被自己改掉，结果静默出错。
  修法：先把 `lo/hi` 的值拷成 `double`，再遍历改写。
- 本机网络：`github.com` 网页不通，`api.github.com` / `raw.githubusercontent.com` /
  `ssh.github.com:443` 通。git 远端统一走 SSH（见 `~/.ssh/config`）。

## 环境

Ubuntu 24.04 · g++ 13.3 · CMake 3.28 · C++20
