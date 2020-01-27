#!/bin/bash

echo "Enter first filename: "
read file1

echo "Enter second filename: "
read file2

if [ $file1 -nt $file2 ]; then
    echo "First file is newer"
else
    echo "Second file is newer"
fi
