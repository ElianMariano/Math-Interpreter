CC=gcc
DIR=build

output: main.o
	@echo "Depends on $^"
	$(CC) -o output main.o
	mv main.o $(DIR)

main.o: main.c
	$(CC) -c main.c

clear:
	rm -rf output
	rm -rf $(DIR)/*.o