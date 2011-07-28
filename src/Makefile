../bin/libvec2d.a:	vector2d.o point2d.o
	ar rc libvec2d.a vector2d.o point2d.o
	rm vector2d.o point2d.o
	mkdir ../bin/
	mv libvec2d.a ../bin/
	cp libvec2d.h ../bin/
	
vector2d.o: vector2d.cpp
	g++ -c -arch i386 vector2d.cpp
	
point2d.o: point2d.cpp
	g++ -c -arch i386 point2d.cpp
	
clean:
	rm -r ../bin/
	rm ../test/testpoint2d
	rm ../test/testvector2d
	
test: ../bin/libvec2d.a ../test/testpoint2d ../test/testvector2d
	../test/testpoint2d
	../test/testvector2d
	
../test/testpoint2d:
	g++ -arch i386 -o ../test/testpoint2d ../test/testpoint2d.cpp -I../bin/ -L../bin/ -lvec2d

../test/testvector2d:
	g++ -arch i386 -o ../test/testvector2d ../test/testvector2d.cpp -I../bin/ -L../bin/ -lvec2d
	
doc:
	doxygen Doxyfile