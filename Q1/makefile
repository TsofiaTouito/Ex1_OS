# Compiler
CC = g++

# Files
FILE_A = Q1_a.cpp
FILE_B = Q1_b.cpp
FILE_C = Q1_c.cpp

# Executables
EXEC_A = a_program
EXEC_B = b_program
EXEC_C = c_program

# Default target: compile and run
.PHONY: all
all: a b c

# Compile and run Q1_a.cpp
a: $(FILE_A)
	$(CC) -o $(EXEC_A) $(FILE_A)
	./$(EXEC_A)

# Compile and run Q1_b.cpp
b: $(FILE_B)
	$(CC) -o $(EXEC_B) $(FILE_B)
	./$(EXEC_B)

# Compile and run Q1_c.cpp
c: $(FILE_C)
	$(CC) -o $(EXEC_C) $(FILE_C)
	./$(EXEC_C)

# Run Q1_a.cpp with gdb
a_gdb: $(FILE_A)
	$(CC) -g -o $(EXEC_A) $(FILE_A)
	gdb ./$(EXEC_A)

# Run Q1_b.cpp with gdb
b_gdb: $(FILE_B)
	$(CC) -g -o $(EXEC_B) $(FILE_B)
	gdb ./$(EXEC_B)

# Run Q1_c.cpp with gdb
c_gdb: $(FILE_C)
	$(CC) -g -o $(EXEC_C) $(FILE_C)
	gdb ./$(EXEC_C)

# Run Q1_a.cpp with ddd
a_ddd: $(FILE_A)
	$(CC) -g -o $(EXEC_A) $(FILE_A)
	ddd ./$(EXEC_A)

# Run Q1_b.cpp with ddd
b_ddd: $(FILE_B)
	$(CC) -g -o $(EXEC_B) $(FILE_B)
	ddd ./$(EXEC_B)

# Run Q1_c.cpp with ddd
c_ddd: $(FILE_C)
	$(CC) -g -o $(EXEC_C) $(FILE_C)
	ddd ./$(EXEC_C)

# Clean up all executables
.PHONY: clean
clean:
	rm -f $(EXEC_A) $(EXEC_B) $(EXEC_C)
