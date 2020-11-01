#!/bin/bash

IFS=$'\n'
file='output.csv'

./a.out units/test_scenario1.json >> $file
./a.out units/test_scenario2.json >> $file
./a.out units/test_scenario3.json >> $file
./a.out units/test_scenario4.json >> $file
./a.out units/test_scenario5.json >> $file
./a.out units/test_scenario6.json >> $file
