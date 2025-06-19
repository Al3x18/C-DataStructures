SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# File sorgenti e oggetti
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET = $(BUILD_DIR)/exe

# Regole principali
all: directories $(TARGET)

# Crea le directory necessarie
directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)

# Compila il programma
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compila i file oggetto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Pulisce i file compilati
clean:
	rm -rf $(BUILD_DIR)

# Esegue il programma
run: all
	./$(TARGET)

.PHONY: all directories clean run