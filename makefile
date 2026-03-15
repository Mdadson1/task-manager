CXX= g++
CXXFLAGS= -Wall

main: TaskList.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp TaskList.o -o main

TaskList.o: TaskList.h TaskList.cpp
	$(CXX) $(CXXFLAGS) -c TaskList.cpp

run: 
	./main

leaks:
	leaks -atExit -- ./main