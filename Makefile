CC=gcc
DIR=build
OBJ = main.o error_handler.o content_sanitizer.o binary_tree.o info.o interpreter.o

output: $(OBJ)
	@echo "Compiling object files $^"
	$(CC) -o output $^
	mv *.o $(DIR)

%.o: %.c
	@echo "Compiling file $<"
	$(CC) -c $<

clear:
	rm -rf output
	rm -rf $(DIR)/*.o