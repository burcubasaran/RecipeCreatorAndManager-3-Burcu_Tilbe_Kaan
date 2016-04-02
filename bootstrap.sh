#!/usr/bin/env bash


# Get the development tools & deps
apt-get update
apt-get install -y build-essential clang cmake libpcre3-dev libgcrypt11-dev libicu-dev libsqlite3-dev sqlite3
cd

#
# Build & install CppCMS
#
CPPCMS_VER='1.0.5'
CPPCMS_NAME="cppcms-$CPPCMS_VER"
CPPCMS_SHA512SUM="88a052df1713e39af87781bccddc42840a34683df86683b846828786e23495bcef5e47eef9e14fad8b0853c665d51c4c17cc79909824cfc2df18776e2676feb3  $CPPCMS_NAME.tar.bz2"

wget "https://sourceforge.net/projects/cppcms/files/cppcms/$CPPCMS_VER/$CPPCMS_NAME.tar.bz2/download" \
     -O "$CPPCMS_NAME.tar.bz2" --progress=dot:mega
echo $CPPCMS_SHA512SUM | sha512sum -c - ; [[ $? != 0 ]] && exit 1
tar -xf "$CPPCMS_NAME.tar.bz2"
cd "$CPPCMS_NAME"
mkdir "build"
cd "build"
cmake \
    -DDISABLE_GZIP=ON \
    -DDISABLE_SCGI=ON \
    -DDISABLE_FCGI=ON \
    ..
make -j$(nproc)
make install
cd


#
# Build and install sqlite_modern_cpp
#
MSQLITE_VER='2.2'
MSQLITE_NAME="sqlite_modern_cpp-$MSQLITE_VER"
MSQLITE_SHA512SUM="45581530063367589d3fd43586a4e277ea21fb5991d699e50a609dfd65a19233faddeb5d983f4378c88f374f1d45a7c2f843624a61738e2f24e979fc6301e58d  $MSQLITE_NAME.tar.gz"

wget "https://github.com/aminroosta/sqlite_modern_cpp/archive/v$MSQLITE_VER.tar.gz" \
     -O "$MSQLITE_NAME.tar.gz" --progress=dot:mega
echo $MSQLITE_SHA512SUM | sha512sum -c - ; [[ $? != 0 ]] && exit 1
tar -xf "$MSQLITE_NAME.tar.gz"
cd "$MSQLITE_NAME"
./configure
make
make install
cd

# Add local libraries to library path
echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib' > /etc/profile.d/local_lib.sh
