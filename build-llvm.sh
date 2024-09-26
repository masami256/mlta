#!/bin/bash -e


# LLVM version: 18.1.8

ROOT=$(pwd)
git clone git@github.com:llvm/llvm-project.git
cd $ROOT/llvm-project
git checkout 3b5b5c1ec4a3095ab096dd780e84d7ab81f3d7ff

if [ ! -d "build" ]; then
  mkdir build
fi

cd build

cmake -DLLVM_TARGET_ARCH="X86" \
			-DLLVM_TARGETS_TO_BUILD="ARM;X86;AArch64" \
			-DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=WebAssembly \
			-DCMAKE_BUILD_TYPE=Release \
			-DLLVM_ENABLE_PROJECTS="clang;lldb" \
			-G "Unix Makefiles" \
			../llvm

make -j$(nproc)

if [ ! -d "$ROOT/llvm-project/prefix" ]; then
  mkdir $ROOT/llvm-project/prefix
fi

cmake -DCMAKE_INSTALL_PREFIX=$ROOT/llvm-project/prefix -P cmake_install.cmake
