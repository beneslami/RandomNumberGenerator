CXX = g++
CXXFLAGS = -Wall -std=c++11

# Object files
OBJS = main.o RandomGenerator.o ReadFile.o Traffic_Model.o

# Executable name
EXEC = model.exe

# Default target
all: $(EXEC)

# Linking rule
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compile rules
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

RandomGenerator.o: RandomGenerator.cpp RandomGenerator.h
	$(CXX) $(CXXFLAGS) -c RandomGenerator.cpp

ReadFile.o: ReadFile.cpp ReadFile.h
	$(CXX) $(CXXFLAGS) -c ReadFile.cpp

Traffic_Model.o: Traffic_Model.cpp Traffic_Model.h
	$(CXX) $(CXXFLAGS) -c Traffic_Model.cpp

# Clean rule
clean:
	rm -f $(OBJS) $(EXEC)