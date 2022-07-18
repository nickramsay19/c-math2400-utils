all: dist/contFraction

dist/contFraction: dist build/main.o build/Fraction.o
	gcc -o dist/contFraction build/main.o build/Fraction.o

build/main.o: build src/main.c
	gcc -o build/main.o -c src/main.c

build/Fraction.o: build src/Fraction.c
	gcc -o build/Fraction.o -c src/Fraction.c

dist:
	mkdir dist

build:
	mkdir build

clean:
	rm -fr dist
	rm -fr build