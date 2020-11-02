OBJS := main.o Player.o Character.o JSONParser.o 
CFLAGS := -std=c++17 -Wall -Werror -g 
CC := g++
UNIT1 := units/unit1.json
UNIT2 := units/unit2.json
UNIT3 := units/unit3.json
BAD_UNIT := unit_testing/missing_comma.json
FSYS_FLAG := -lstdc++fs
OUTBIN := a.out

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTBIN) $(OBJS) $(FSYS_FLAG)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp Character.h Player.h JSONParser.h $(FSYS_FLAG)

JSONParser.o: JSONParser.cpp JSONParser.h
	$(CC) $(CFLAGS) -c JSONParser.cpp JSONParser.h Character.h $(FSYS_FLAG)

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) -c Player.cpp Player.h Character.h $(FSYS_FLAG)

Character.o: Character.cpp Character.h
	$(CC) $(CFLAGS) -c Character.cpp Character.h JSONParser.h $(FSYS_FLAG)

doc_gen:
	doxygen -g
	doxygen Doxyfile

act_fight_removal:
	rm -f output.csv

act_fight:
	touch "output.csv"
	> output.csv
	./a.out $(UNIT1) $(UNIT2) >> output.csv
	./a.out $(UNIT1) $(UNIT3) >> output.csv
	./a.out $(UNIT2) $(UNIT1) >> output.csv
	./a.out $(UNIT2) $(UNIT3) >> output.csv
	./a.out $(UNIT3) $(UNIT2) >> output.csv
	./a.out $(UNIT3) $(UNIT1) >> output.csv

act_fight_diff:
	diff output.csv expected_output.csv
	
clean:
	rm -rf *.o *.out

cppcheck:
	echo "$$(cppcheck *.cpp --enable=warning --output-file=warning_log.txt)"
	if [ -s ./warning_log.txt ]
	then
		echo "Errors and/or warnings found."
		exit 1
	else
		echo "No errors or warnings found."
		echo "$$(cppcheck *.cpp --enable=performance,style --output-file=perf-style_log.txt)"
		if [ -s ./perf-style_log.txt ]
		then
			echo "Performance and/or style problems found."
		else
			echo "No performance or style problems found."
		fi
	fi

memtest:
	command="$$(valgrind --leak-check=yes --log-file=memtest_log.txt ./a.out $(UNIT1) $(UNIT2))"
	result="$$(cat ./memtest_log.txt)"
	echo $$result
	if [ "$$(echo $$result | sed 's/^.*ERROR SUMMARY: \([0-9]*\) errors.*$$/\1/')" == "0" ]
	then
		echo "No memory leak(s) found."
	else
		echo "Memory leak(s) found. Quitting."
		exit 1
	fi

google_test_first:
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a

google_test_second:
	cmake unit_testing/CMakeLists.txt
	cd unit_testing && make && ./runTests