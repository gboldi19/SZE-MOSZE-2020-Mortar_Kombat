OBJS := main.o Hero.o Character.o JSON.o 
CFLAGS := -std=c++17 -Wall -Werror -g 
CC := g++-10
UNIT1 := units/test_scenario1.json
UNIT2 := units/test_scenario2.json
UNIT3 := units/test_scenario3.json
UNIT4 := units/test_scenario4.json
UNIT5 := units/test_scenario5.json
UNIT6 := units/test_scenario6.json
BAD_UNIT := unit_testing/missing_comma.json
FSYS_FLAG := -lstdc++fs
OUTBIN := a.out

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTBIN) $(OBJS) $(FSYS_FLAG)

main.o: main.cpp Character.h Hero.h JSON.h
	$(CC) $(CFLAGS) -c main.cpp $(FSYS_FLAG)

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp $(FSYS_FLAG)

Hero.o: Hero.cpp Hero.h Character.h JSON.h
	$(CC) $(CFLAGS) -c Hero.cpp $(FSYS_FLAG)

Character.o: Character.cpp Character.h JSON.h
	$(CC) $(CFLAGS) -c Character.cpp $(FSYS_FLAG)

Monster.o: Monster.cpp Monster.h Character.h JSON.h
	$(CC) $(CFLAGS) -c Monster.cpp $(FSYS_FLAG)

doc_generation:
	doxygen -g
	doxygen Doxyfile

static_fight_output_removal:
	rm -f output.csv

static_fight_scenario:
	touch "output.csv"
	> output.csv
	./a.out $(UNIT1) >> output.csv
	./a.out $(UNIT2) >> output.csv
	./a.out $(UNIT3) >> output.csv
	./a.out $(UNIT4) >> output.csv
	./a.out $(UNIT5) >> output.csv
	./a.out $(UNIT6) >> output.csv

static_fight_diff:
	diff output.csv expected_output1.csv
	
clean:
	rm -rf *.o *.out

static_code_analysis:
	echo "$$(cppcheck *.cpp --enable=warning --output-file=warning_log.txt)"; \
	if [ -s ./warning_log.txt ]; \
	then \
		echo "Errors and/or warnings found."; \
		exit 1; \
	else \
		echo "No errors or warnings found."; \
		echo "$$(cppcheck *.cpp --enable=performance,style --output-file=perf-style_log.txt)"; \
		if [ -s ./perf-style_log.txt ]; \
		then \
			echo "Performance and/or style problems found."; \
		else \
			echo "No performance or style problems found."; \
		fi \
	fi

memory_leak_testing:
	valgrind --error-exitcode=1 --leak-check=full ./a.out $(UNIT1)

google_test_first:
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a

google_test_second:
	cmake unit_testing/CMakeLists.txt
	cd unit_testing && make && ./runTests