SRC_DIR = ./src
INC_DIR = ./src

OUT_DIR = ./build
OBJ_DIR = $(OUT_DIR)/obj
BIN_DIR = $(OUT_DIR)/bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

include $(wildcard $(OBJ_DIR)/*.d)

all: $(OBJ_FILES)

	@echo "linking object files to create executable"
	@mkdir -p $(BIN_DIR)
	@gcc $(OBJ_FILES) -o $(BIN_DIR)/app.out
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $< to $@"
	@mkdir -p $(OBJ_DIR)
	@gcc -o $@ -c $< -I $(INC_DIR)	-MMD


clean:
	@rm -rf $(OUT_DIR)

info:
	echo "OBJ_FILES=$(OBJ_FILES)"

doc:
	@doxygen Doxyfile
run: all
	@$(BIN_DIR)/app.out
