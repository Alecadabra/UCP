#!/bin/bash

echo "Enter filename: "
read filename

echo "File is "

if [ -r $filename ]; then
    echo "readable "
fi

if [ -w $filename ]; then
    echo "writable "
fi

if [ -x $filename ]; then
    echo "executable"
fi
