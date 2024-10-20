CXX = g++
CXXFLAGS = -fprofile-arcs -ftest-coverage
TARGET = dijkstra_program
SOURCE = Graph.cpp
GCOV_FILE = dijkstra_program-Graph.cpp

# Rule to build the executable
all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

# Rule to generate coverage report
coverage: run
	gcov $(GCOV_FILE)

# Rule to clean up generated files
clean:
	rm -f $(TARGET) *.gcda *.gcno *.gcov

.PHONY: all run coverage clean
