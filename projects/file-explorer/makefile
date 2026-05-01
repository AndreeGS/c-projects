# ==============================
# Password Manager - Makefile
# ==============================

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -std=c11 -I./models -I./crypto -I./storage -I./vault
LDFLAGS = -lcrypto

# Nome do executável
TARGET = password_manager

# Diretórios
SRC_DIRS = crypto models storage vault

# Arquivos fonte
SRCS = main.c $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# Objetos
OBJS = $(SRCS:.c=.o)

# ==============================
# Build principal
# ==============================

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# ==============================
# Compilação dos .c
# ==============================

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ==============================
# Limpeza
# ==============================

clean:
	rm -f $(OBJS) $(TARGET)

# ==============================
# Rebuild completo
# ==============================

rebuild: clean all

.PHONY: all clean rebuild