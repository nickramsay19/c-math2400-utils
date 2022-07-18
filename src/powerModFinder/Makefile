all: dist/powerModFinder

dist/powerModFinder: dist build/main.o
	gcc -o dist/powerModFinder build/main.o

build/main.o: build src/main.c
	gcc -o build/main.o -c src/main.c

dist:
	mkdir dist

build:
	mkdir build

clean:
	rm -fr dist
	rm -fr build