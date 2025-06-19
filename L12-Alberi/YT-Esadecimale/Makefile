CC = gcc
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET = $(BUILD_DIR)/exe

# Main target
all: $(TARGET)

#linking
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

#compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#run
run: rebuild
	@mkdir -p $(OBJ_DIR) $(BUILD_DIR)
	./$(TARGET)

#clean
clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)
	rm -f out.svg
	rm -f tree.dot

#rebuild
rebuild: clean all

.PHONY: all run clean rebuild
