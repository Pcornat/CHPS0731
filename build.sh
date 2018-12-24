#!/usr/bin/env bash
cmake --build cmake-build-release/ --target RayTrace -- -j
mv cmake-build-release/RayTrace prog
