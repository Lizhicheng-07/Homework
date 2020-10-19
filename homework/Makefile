testmymath:main.o add.o sub.o mul.o div.o
	gcc main.o add.o sub.o mul.o div.o -o testmymath
main.o:main.c head_20209322.h
	gcc -c main.c -o main.o
add.o:add.c head_20209322.h
	gcc -c add.c -o add.o
sub.o:sub.c head_20209322.h
	gcc -c sub.c -o sub.o
mul.o:mul.c head_20209322.h
	gcc -c mul.c -o mul.o
div.o:div.c head_20209322.h
	gcc -c div.c -o div.o
clean:
	rm -f *.o testmymath
