#!/bin/bash

for var in $(find -type f); do
    for var2 in $(find -type f); do
        if [ ! $var = $var2 ]; then
            if diff $var $var2 &>/dev/null; then
                echo "$var and $var2"
            fi
        fi
    done
done 

# Old Code
: <<'END'
for var in $@; do
    for var2 in $@; do
        if [ ! $var = $var2 ]; then
            if diff $var $var2 &>/dev/null; then
                echo "$var and $var2"
            fi
        fi
    done
done 
END
