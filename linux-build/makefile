all: ../classes/Main.cpp ClassTime.o Lecture.o Course.o
	g++ -I../JsonBox/include -I./include -I../include ../JsonBox/build/objs/*.o ../classes/Main.cpp ./bin/*.o -o ./bin/timetable -g

ClassTime.o: ../classes/ClassTime.cpp ../include/ClassTime.h
	mkdir -p bin
	g++ -I../JsonBox/include -I../include ../classes/ClassTime.cpp -o ./bin/ClassTime.o -c -g

Lecture.o: ../classes/Lecture.cpp ../include/Lecture.h
	mkdir -p bin
	g++ -I../JsonBox/include -I../include ../classes/Lecture.cpp -o ./bin/Lecture.o -c -g

Course.o: ../classes/Course.cpp ../include/Course.h
	mkdir -p bin
	g++ -I../JsonBox/include -I../include ../classes/Course.cpp -o ./bin/Course.o -c -g


clean:
	rm ./bin/*.o
