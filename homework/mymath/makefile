Head=head_20209322.h
vpath %.c src
vpath %.h include
vpath %.a lib
vpath %.so lib
testmymath:main.o add.o sub.o mul.o div.o
	gcc main.o add.o sub.o mul.o div.o -o testmymath
main.o:main.c $(Head)
	gcc -c -Iinclude src/main.c
add.o:add.c $(Head)
	gcc -c -Iinclude src/add.c
sub.o:sub.c $(Head)
	gcc -c -Iinclude src/sub.c
mul.o:mul.c $(Head)
	gcc -c -Iinclude src/mul.c
div.o:div.c $(Head)
	gcc -c -Iinclude src/div.c

