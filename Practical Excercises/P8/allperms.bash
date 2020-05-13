#!/bin/bash

for var in $(find -type f); do
    if [ ! -e $var ]; then
        echo "$var does not exist"
    elif [ -r $var ] && [ -w $var ] && [ -x $var ]; then
        echo "$var is readable, writable and executable"
    elif [ -r $var ] && [ -w $var ]; then
        echo "$var is readable and writable"
    elif [ -r $var ] && [ -x $var ]; then
        echo "$var is readable and executable"
    elif [ -w $var ] && [ -x $var ]; then
        echo "$var is writable and executable"
    elif [ -w $var ]; then
        echo "$var is writable"
    elif [ -r $var ]; then
        echo "$var is readable"
    elif [ -x $var ]; then
        echo "$var is executable"
    else
        echo "$var has no permissions"
    fi
done

# Old Code
: <<'END'
for var in $@; do
    if [ ! -e $var ]; then
        echo "$var does not exist"
    elif [ -r $var ] && [ -w $var ] && [ -x $var ]; then
        echo "$var is readable, writable and executable"
    elif [ -r $var ] && [ -w $var ]; then
        echo "$var is readable and writable"
    elif [ -r $var ] && [ -x $var ]; then
        echo "$var is readable and executable"
    elif [ -w $var ] && [ -x $var ]; then
        echo "$var is writable and executable"
    elif [ -w $var ]; then
        echo "$var is writable"
    elif [ -r $var ]; then
        echo "$var is readable"
    elif [ -x $var ]; then
        echo "$var is executable"
    else
        echo "$var has no permissions"
    fi
done
END
