#!/usr/bin/env bash
cd cmake-build-release/
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$1 -DCMAKE_CXX_COMPILER=$2 -G "CodeBlocks - Unix Makefiles" ../
cd ../
