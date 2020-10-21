#!/bin/bash

IFS=$'\n'
echo "$(cppcheck *.cpp --enable=warning --output-file=warning_log.txt)"
if [ -s ./warning_log.txt ]
then
    echo "Errors and/or warnings found."
    exit 1
else
    echo "No errors or warnings found."
    echo "$(cppcheck *.cpp --enable=performance,style --output-file=perf-style_log.txt)"
    if [ -s ./perf-style_log.txt ]
    then
        echo "Performance and/or style problems found."
    else
        echo "No performance or style problems found."
    fi
fi
