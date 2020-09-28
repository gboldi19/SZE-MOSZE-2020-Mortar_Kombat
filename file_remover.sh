#!/bin/bash

file=$1

if [ -f $file]; then
    rm $file
fi
