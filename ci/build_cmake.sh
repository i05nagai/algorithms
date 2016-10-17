#!/bin/bash -x

#make dir
mkdir build
ret=$?
if [ $ret -ne 0 ]
then
	exit $ret
fi

#cd build
cd build
ret=$?
if [ $ret -ne 0 ]
then
	exit $ret
fi

#cmake
cmake ..
ret=$?
if [ $ret -ne 0 ]
then
	exit $ret
fi

#make
make
ret=$?
if [ $ret -ne 0 ]
then
	exit $ret
fi

#make test
ctest --verbose
ret=$?
if [ $ret -ne 0 ]
then
	exit $ret
fi

exit 0

