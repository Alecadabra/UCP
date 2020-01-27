#!/bin/bash

file=logfile

if [ $# = 0 ]
then
    echo "a - All log entries recorded on 20 August from"
    echo "    10:21:00am to 10:21:59am."
    echo ""
    echo "b - All log entries containing the words"
    echo "    \"warning\", \"error\" or \"fail\"."
    echo ""
    echo "c - All log entries recorded at a time where"
    echo "    minutes is zero."
    echo ""
    echo "d - All log entries containing an IPv4 addres"
    echo "    - 4 integers seperated by periods."
    echo ""
    echo "e - All log entries containing at least two"
    echo "    IPv4 addresses."
elif [ $1 = a ]
then
    grep -E '^Aug 20 10:21:[0-5][0-9].*$' $file
elif [ $1 = b ]
then
    grep -E '^.*(warning |error |fail )+.*$' $file
elif [ $1 = c ]
then
    grep -E '^... .. ..:00:.*$' $file
elif [ $1 = d ]
then
    grep -E '^.*[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?.*$' $file
elif [ $1 = e ]
then
    grep -E '^.*([0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?)+.*([0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?\.[0-9][0-9]?[0-9]?)+.*$' $file
fi
