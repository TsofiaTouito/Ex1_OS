# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Target executable
TARGET = signal_handler

# Source files
SRCS = main.cpp

# Default rule
all: $(TARGET)

# Link the program
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean rule to remove the executable
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
