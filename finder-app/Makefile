CC := gcc
CFLAGS := -Wall -Wextra
LDFLAGS :=
SRC := writer.c
OBJ := $(SRC:.c=.o)
TARGET := writer

# Check if CROSS_COMPILE is specified
ifdef CROSS_COMPILE
    CC := $(CROSS_COMPILE)gcc
    TARGET := $(TARGET)_cross
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)

