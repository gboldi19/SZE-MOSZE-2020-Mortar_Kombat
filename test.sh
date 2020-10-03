#!/bin/bash

IFS=$'\n'
file='output.csv'

./a.out units/unit1.json units/unit2.json >> $file
./a.out units/unit1.json units/unit3.json >> $file
./a.out units/unit2.json units/unit1.json >> $file
./a.out units/unit2.json units/unit3.json >> $file
./a.out units/unit3.json units/unit2.json >> $file
./a.out units/unit3.json units/unit1.json >> $file
