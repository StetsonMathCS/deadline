deadline: newDeadlineMain.o
	g++ -Wall -lboost_serialization newDeadlineMain.o -o deadline

newDeadlineMain.o: newDeadlineMain.cpp
	g++ -c newDeadlineMain.cpp

clean:
	rm -f newDeadlineMain.o deadline
