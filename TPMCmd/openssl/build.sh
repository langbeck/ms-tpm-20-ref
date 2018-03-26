#!/bin/bash
set -e
cd $(dirname $0)

mkdir -p include/openssl/internal
if [ ! -d src/.git ]; then
    rm -rf src
    git clone --branch OpenSSL_1_1_0g --depth 1 https://github.com/openssl/openssl.git src
fi

cd src
if [ ! -f Makefile ]; then
    ./config
fi
make -j5

cp -r include ../
cp crypto/bn/bn_lcl.h ../include/openssl/bn_lcl.h
cp -r crypto/include/internal ../include/openssl/
