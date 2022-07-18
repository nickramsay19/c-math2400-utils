all: dist/egcd

dist/egcd: dist build/main.o
	gcc -o dist/egcd build/main.o

build/main.o: build src/main.c
	gcc -o build/main.o -c src/main.c

# create build folders
dist:
	mkdir dist

build:
	mkdir build

clean:
	rm -fr dist
	rm -fr build