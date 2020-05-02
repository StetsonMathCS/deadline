CXX = g++
CXXFLAGS = -Wall -o 

carson.o: files.cpp m2.cpp
    $(CXX) $(CXXFLAGS) -c carson.o

hfutch.o: data_struct.cpp
    $(CXX) $(CXXFLAGS) -c hfutch.o

jhill.o: main.cpp
    $(CXX) $(CXXFLAGS) -c jhill.o

moe.o: editor.cpp print.cpp
    $(CXX) $(CXXFLAGS) -c moe.o

timeparsing.o: timeparsing.cpp
    $(CXX) $(CXXFLAGS) -c timeparsing.o

rbabikow.o: deadlineMain.cpp
    $(CXX) $(CXXFLAGS) -c deadlineMain.cpp

deadline: carson.o hfutch.o jhill.o moe.o timeparsing.o rbabikow.o
    $(CXX) $(CXXFLAGS) -o deadline carson.o hfutch.o jhill.o moe.o timeparsing.orbabikow.o
