CXX = g++
CXXFLAGS = -I Basics/Common -Wall -Wextra

test: Basics/Basics/dynamicMemory/malloc.o
	$(CXX) $(CXXFLAGS) -o test Basics/Basics/dynamicMemory/malloc.o

Basics/Basics/dynamicMemory/malloc.o: Basics/Basics/dynamicMemory/malloc.cpp
	$(CXX) $(CXXFLAGS) -c Basics/Basics/dynamicMemory/malloc.cpp -o Basics/Basics/dynamicMemory/malloc.o

clean:
	rm -f Basics/Basics/dynamicMemory/malloc.o test
