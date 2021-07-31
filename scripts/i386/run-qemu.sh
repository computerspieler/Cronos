#!/bin/bash

if [ $# != 5 ]; then
	echo "ERROR: Not the right amount or arguments"
	exit 1
fi

qemu-system-i386 -m 32M -serial stdio -cdrom $1
