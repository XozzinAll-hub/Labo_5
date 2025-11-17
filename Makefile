## Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -g

# Directorios
SRCDIR = src
INCDIR = include

# Archivos fuente (si alguno no existe, ignoralo por ahora)
SOURCES = $(wildcard $(SRCDIR)/*.c)

# Archivos objeto
OBJECTS = $(SOURCES:.c=.o)

# Nombre del ejecutable
TARGET = main

# Regla principal
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Ejecutar
run: $(TARGET)
	./$(TARGET)

# Limpiar
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean run