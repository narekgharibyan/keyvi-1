#!/usr/bin/env bash
set -ex

##  run this script from project root
##
##  docker run --rm -it -v `pwd`:/io narekgharibyan/keyvi-ubuntu-builder:golang /io/go/build_go.sh
##

# build keyvi_c library
mkdir -p /io/build
cd /io/build
cmake ..
make -j keyvi_c

# run go tests
export LD_LIBRARY_PATH=/io/build
cd /io/go
go test
