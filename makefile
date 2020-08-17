CXX = g++
CXXFLAGS = -Wall

all: successful connection unsuccessful

successful: src/demo-successful.cpp
	$(CXX) $(CXXFLAGS) src/demo-successful.cpp -o succcessful

connection: src/connection.cpp
	$(CXX) $(CXXFLAGS) src/connection.cpp -o connection

unsuccessful: src/demo-unsuccessful.cpp
	$(CXX) $(CXXFLAGS) src/demo-unsuccessful.cpp -o unsuccessful

