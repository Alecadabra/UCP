#!/bin/bash

day=$(date +"%d")

for filename in $(find -type f); do
    if [[ "$filename" == *"$day"* ]]; then
        echo "$filename"
    fi
done
