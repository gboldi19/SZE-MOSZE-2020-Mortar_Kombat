OBJS := Character.o JSONParser.o main.o Player.o
CFLAGS := -std=c++17 -Wall -c
CC := g++-10
RUNCPP := Character.cpp JSONParser.cpp main.cpp Player.cpp
UNIT1 := units/unit1.json
UNIT2 := units/unit2.json
UNIT3 := units/unit3.json
BAD_UNIT := unit_testing/missing_comma.json
FSYS_FLAG := -lstdc++fs

combat: $(OBJS)
	$(CC) $(CFLAGS) -o combat $(OBJS) $(FSYS_FLAG)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(FSYS_FLAG)

JSONParser.o: JSONParser.cpp JSONParser.h
	$(CC) $(CFLAGS) JSONParser.cpp $(FSYS_FLAG)

Player.o: Player.cpp Player.h Character.h
	$(CC) $(CFLAGS) Player.cpp $(FSYS_FLAG)

Character.o: Character.cpp Character.h JSONParser.h
	$(CC) $(CFLAGS) Character.cpp $(FSYS_FLAG)

doc_gen:
	doxygen -g
	doxygen Doxyfile

act_fight_removal:
	rm -f output.csv

act_fight:
	file="output.csv"
	$(combat) $(UNIT1) $(UNIT2) >> $$file
	$(combat) $(UNIT1) $(UNIT3) >> $$file
	$(combat) $(UNIT2) $(UNIT1) >> $$file
	$(combat) $(UNIT2) $(UNIT3) >> $$file
	$(combat) $(UNIT3) $(UNIT2) >> $$file
	$(combat) $(UNIT3) $(UNIT1) >> $$file

act_fight_diff:
	diff output.csv expected_output.csv

cppcheck:
	cppcheck *.cpp --enable=warning --output-file=warning_log.txt --error-exitcode=1
	cppcheck *.cpp --enable=warning,style,performance --output-file=perf-style_log.txt

google_test:
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	$(combat)
	cmake unit_testing/CMakeLists.txt
	cd unit_testing && make && ./runTests