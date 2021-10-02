#!/bin/bash
if [ $target == "rg99" ]; then
	target2=rs90
else
	target2=$target
fi

TOOLCHAIN=/opt/$target2-toolchain
if [ $target == "gcw0" ]; then
	SYSROOT=$TOOLCHAIN/mipsel-$target2-linux-uclibc
else
	SYSROOT=$TOOLCHAIN/mipsel-$target2-linux-musl
fi

export PATH=$TOOLCHAIN/usr/bin:$SYSROOT/usr/include:$TOOLCHAIN/bin:$PATH
export CXX=mipsel-linux-g++
export CXXFLAGS="-funsigned-char" # workaround for a scummvm tolower() bug when adding games

if [ $target != "rs90" ]; then
	export LDFLAGS="-Wl,-zcommon-page-size=2097152,-zmax-page-size=2097152 -lhugetlbfs"
fi

if [ $target == "rg99" ]; then
	export DEFINES="-DDISABLE_FANCY_THEMES"
elif [ $target == "gcw0" ]; then
	export DEFINES="-DGCW0"
fi

CONFIG="./configure --host=opendingux --enable-release --disable-detection-full"

case $target in
	
	gcw0)
	;;

	lepus)
	CONFIG+=" --disable-highres"
	;;

	rg99)
	CONFIG+=" --disable-highres --disable-16bit --disable-scalers"
	;;
	
	*)
	echo "please provide a valid target for the build: gcw0, lepus or rg99"
	exit 0
	;;
esac

$CONFIG && make -j12 od-make-opk && ls -lh scummvm_$target*.opk
