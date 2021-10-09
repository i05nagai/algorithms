#!/bin/bash -x

ctest -T memcheck --verbose | tee memcheck.log

ret=${PIPESTATUS[0]}
if [ $ret -ne 0 ]
then
	exit $ret
fi
cat memcheck.log | grep "Memory Leak" > /dev/null
ret=$?
if [ $ret -eq 0 ]
then
	exit 1
fi
