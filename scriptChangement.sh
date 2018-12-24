#!/usr/bin/env bash
cd cmake-build-release/
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=$1 -G "CodeBlocks - Unix Makefiles" ../
cd ../
