# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -g

# Directorios
SRCDIR = src
INCDIR = include

# Archivos fuente
SOURCES = $(SRCDIR)/main.c \
          $(SRCDIR)/dynamic_array.c \
          $(SRCDIR)/linked_list.c \
          $(SRCDIR)/doubly_linked_list.c \
          $(SRCDIR)/stack.c

# Archivos objeto (se generan automáticamente)
OBJECTS = $(SOURCES:.c=.o)

# Nombre del ejecutable
TARGET = main

# Regla principal
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJECTS) $(TARGET)

# Para evitar conflictos con archivos que se llamen igual
.PHONY: clean