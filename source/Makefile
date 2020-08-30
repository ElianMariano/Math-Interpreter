CC=gcc
DIR=build
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(SRC))

output: $(OBJ)
	@echo "Linking object files $^"
	$(CC) -o output $^

	if [ ! -d "$(DIR)" ]; then \
		echo "Creating '$(DIR)' folder"; \
		mkdir $(DIR); \
	fi

	@echo "Moving file to $(DIR) directory"
	mv *.o $(DIR)

$(OBJ): $(SRC)
	for i in $(SRC); do \
		echo "Compiling file $$i"; \
		$(CC) -c $$i; \
	done

clear:
	rm -rf output
	rm -rf $(DIR)/*.o
