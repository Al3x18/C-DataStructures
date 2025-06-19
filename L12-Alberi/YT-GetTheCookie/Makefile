CC = gcc
CFLAGS = -Wall -Wextra -g
SRC_DIR = src
BUILD_DIR = build
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/prototipi.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
EXEC = $(BUILD_DIR)/bst_program

all: $(BUILD_DIR) $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run 