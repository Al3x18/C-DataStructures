#Nome dell'eseguibile
#TARGET = exe_test

#Cartelle
SRC_DIR = src
BUILD_DIR = build

# Default main file (can be overridden with make MAIN=file_name)
MAIN ?= test_multipli_ordina_array

# Target name based on main file
TARGET = $(MAIN)

# Trova tutti i file .c nella cartella src tranne i file con main
SRC_BASE = $(filter-out $(SRC_DIR)/test_%.c, $(wildcard $(SRC_DIR)/*.c))

# Aggiungi il file main specificato
SRC = $(SRC_BASE) $(SRC_DIR)/$(MAIN).c

# Crea i percorsi dei file oggetto corrispondenti nella build/
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

# Compilatore e flag
CC = gcc
CFLAGS = -Wall -I$(SRC_DIR)

# Regola di default
all: $(TARGET)

# Regola di compilazione principale: crea l'eseguibile
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Regola per i file oggetto: crea un file oggetto per ogni file .c
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per pulire i file oggetto e l'eseguibile
clean:
	rm -rf $(BUILD_DIR) $(TARGET) outputs/*

# Mostra i target disponibili
list:
	@echo "Available main files:"
	@ls -1 $(SRC_DIR)/test_*.c | sed 's/.*\/\(.*\)\.c/\1/'
