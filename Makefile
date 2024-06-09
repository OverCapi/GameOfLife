# Nom de l'exécutable
TARGET = gameOfLife.out

# Répertoires
SRCS_DIR = srcs

# Fichiers source
SRCS_FILES = $(SRCS_DIR)/main.c \
             $(SRCS_DIR)/game.c \
			 $(SRCS_DIR)/map.c

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/usr/local/include
LDFLAGS = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Règles de compilation
all: $(TARGET)

$(TARGET): $(SRCS_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
