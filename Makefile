CC := gcc
CFLAGS := -g -Wextra -Wall -O0
BUILD_DIR := build
OBJECT_DIR := $(BUILD_DIR)/object
.PHONY: all run clean

all: $(BUILD_DIR)/main
run: $(BUILD_DIR)/main
	$<
$(BUILD_DIR)/main: $(OBJECT_DIR)/main.o $(OBJECT_DIR)/formatter.o
	$(CC) $(CFLAGS) $^ -o $@
$(OBJECT_DIR)/%.o: %.c | $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJECT_DIR):
	@mkdir -p $@
clean:
	rm -rf $(BUILD_DIR)