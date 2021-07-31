student: main.cpp students.cpp
	g++ -o student main.cpp students.cpp

clean:
	rm -f student main.o students.o