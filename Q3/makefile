all: libpoisson.so main

libpoisson.so: poisson.o
	gcc -shared -fPIC -o libpoisson.so poisson.o -lm 

poisson.o: poisson.c poisson.h
	gcc -c poisson.c

main: main.c libpoisson.so
	gcc -o main main.c -L. -lpoisson -Wl,-rpath=. -lm

clean:
	rm -f poisson.o libpoisson.so main

# -fPIC: Generates position-independent code for shared libraries
# -L.: Look for libraries in the current directory
# -Wl: Pass options to the linker
# -rpath=.: Set runtime library search path to current directory
