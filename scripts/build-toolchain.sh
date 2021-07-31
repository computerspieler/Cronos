#!/bin/bash

if [ $# != 2 ]; then
	echo "ERROR: Not the right amount of arguments"
	echo "./scripts/build-toolchain.sh <TARGET> <OUTPUT DIR>"
	exit 1
fi

export BINUTILS_VERSION=2.34
export GCC_VERSION=9.3.0
export PREFIX=$2
export TARGET=$1
export PATH="$PREFIX/bin:$PATH"

mkdir -p tmp
cd tmp

echo ==== Build a toolchain which target $TARGET ====
echo ==== Download tarballs ====
if [ ! -f binutils-$BINUTILS_VERSION.tar.gz ]; then
	wget https://gcc.gnu.org/pub/binutils/releases/binutils-$BINUTILS_VERSION.tar.gz
fi
if [ ! -f gcc-$GCC_VERSION.tar.gz ]; then
	wget https://gcc.gnu.org/pub/gcc/releases/gcc-$GCC_VERSION/gcc-$GCC_VERSION.tar.gz
fi

echo ==== Extract tarballs ====
if [ ! -d binutils-$BINUTILS_VERSION ]; then
	tar xvf binutils-$BINUTILS_VERSION.tar.gz
fi
if [ ! -d gcc-$GCC_VERSION ]; then
	tar xvf gcc-$GCC_VERSION.tar.gz
fi

mkdir -p $PREFIX

if [ ! -d build-binutils-$BINUTILS_VERSION-$TARGET ]; then 
echo ==== Build binutils ====
mkdir -p build-binutils-$BINUTILS_VERSION-$TARGET
cd build-binutils-$BINUTILS_VERSION-$TARGET
../binutils-$BINUTILS_VERSION/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
#make
#make install
cd ..
else
echo ==== Binutils already built ====
fi

if [ ! -d build-gcc-$GCC_VERSION-$TARGET ]; then 
echo ==== Build GCC ====
mkdir -p build-gcc-$GCC_VERSION-$TARGET
cd build-gcc-$GCC_VERSION-$TARGET
../gcc-$GCC_VERSION/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
#make all-gcc
#make all-target-libgcc
#make install-gcc
#make install-target-libgcc
cd ..
else
echo ==== GCC already built ====
fi
cd ..
