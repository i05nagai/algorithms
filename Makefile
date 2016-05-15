

quasi_newton: quasi_newton/Makefile
	cd quasi_newton; make
	cd ..

document: Doxyfile
	doxygen Doxyfile
