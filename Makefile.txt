CC = gcc
CFLAGS = -Wall -Wextra -g3 -Iinclude

SRC_DIR = .
OBJ_DIR = build
OUT_FILE = build/game

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(OUT_FILE)

$(OUT_FILE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(OUT_FILE)
