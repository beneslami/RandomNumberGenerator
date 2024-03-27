CXX = g++
CXXFLAGS = -Wall -std=c++11

# Object files
OBJS = main.o RandomGenerator.o ReadFile.o Traffic_Model.o MarkovChain.o Temporal_Locality.o

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

MarkovChain.o: MarkovChain.cpp MarkovChain.h
	$(CXX) $(CXXFLAGS) -c MarkovChain.cpp

Temporal_Locality.o: Temporal_Locality.cpp Temporal_Locality.h
	$(CXX) $(CXXFLAGS) -c Temporal_Locality.cpp

# Clean rule
clean:
	rm -f $(OBJS) $(EXEC)