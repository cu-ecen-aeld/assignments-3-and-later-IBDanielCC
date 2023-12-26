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

# Print PATH and CC for debugging
$(info PATH is $(PATH))
$(info CC is $(CC))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	/home/daniel/arm-cross-compiler/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	/home/daniel/arm-cross-compiler/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc $(CFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
