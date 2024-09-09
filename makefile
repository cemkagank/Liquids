make:
	g++ src/main.cpp -O2 -lraylib -lGL  -o build/liquids -Iinclude/

run:
	./build/liquids
