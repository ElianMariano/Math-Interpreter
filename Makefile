CC=gcc
DIR=build
OBJ=$(shell ls *.o)

output: error_handler.o content_sanitizer.o binary_tree.o main.o
	$(CC) -o output main.o error_handler.o content_sanitizer.o binary_tree.o
	mv *.o $(DIR)

main.o: main.c
	$(CC) -c main.c

error_handler.o: error_handler.c error_handler.h
	$(CC) -c error_handler.c

content_sanitizer.o: content_sanitizer.c content_sanitizer.h
	$(CC) -c content_sanitizer.c

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) -c binary_tree.c

clear:
	rm -rf output
	rm -rf $(DIR)/*.o