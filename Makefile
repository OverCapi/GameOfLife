# Nom de l'exécutable
TARGET = gameOfLife.out

# Fichiers source
SRCS_DIR = srcs
SRCS_FILES = $(SRCS_DIR)/main.c \
			 $(SRCS_DIR)/game.c

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Règles de compilation
all: $(TARGET)

$(TARGET): $(SRCS_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

