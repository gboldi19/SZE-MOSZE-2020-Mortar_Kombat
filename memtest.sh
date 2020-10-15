IFS=$'\n'
command="$(valgrind --leak-check=yes --log-file=memtest_log.txt ./a.out units/unit1.json units/unit2.json)"
result="$(cat ./memtest_log.txt)"
echo $result
if [ "$(echo $result | sed 's/^.*ERROR SUMMARY: \([0-9]*\) errors.*$/\1/')" == "0" ]
then
    echo "No memory leak(s) found."
else
    echo "Memory leak(s) found. Quitting."
    exit 1
fi
