all: gcd egcd inverseFinder divmod powerModFinder

gcd: dist src/gcd/Makefile
	make -C src/gcd clean
	make -C src/gcd all
	mv src/gcd/dist/* dist

egcd: dist src/egcd/Makefile
	make -C src/egcd clean
	make -C src/egcd all
	mv src/egcd/dist/* dist

inverseFinder: dist src/inverseFinder/Makefile
	make -C src/inverseFinder clean
	make -C src/inverseFinder all
	mv src/inverseFinder/dist/* dist

divmod: dist src/divmod/Makefile
	make -C src/divmod clean
	make -C src/divmod all
	mv src/divmod/dist/* dist

powerModFinder: dist src/powerModFinder/Makefile 
	make -C src/powerModFinder clean
	make -C src/powerModFinder all
	mv src/powerModFinder/dist/* dist

irreducibleFinder: dist src/irreducibleFinder/Makefile 
	make -C src/irreducibleFinder clean
	make -C src/irreducibleFinder all
	mv src/irreducibleFinder/dist/* dist

# create required containing folders
dist:
	mkdir dist

clean:
	rm -fr dist