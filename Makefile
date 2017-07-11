all: vec unit

vec: vec.cpp
	g++ vec.cpp -Wall -o vec

unit: vec.cpp unittest.cpp
	g++ vec.cpp unittest.cpp -Wall -o unittest -D UNIT_TEST

clean:
	rm -f vec
	rm -f unittest
