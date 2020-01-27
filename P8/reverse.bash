#!/bin/bash

# Uses rev command and imports everything from command line and redirects
# all output to variable reversed
reversed=$(rev<<<$*)

echo $reversed
