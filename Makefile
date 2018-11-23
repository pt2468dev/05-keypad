# Name of the resulting program/hex file
PROGRAM_NAME = output

# Microcontroller
MCU = atmega2560

# Clock speed
CLOCK = 16000000

# AVR DUDE
PROGRAMMER = wiring
BAUD       = 115200
PORT       = /dev/ttyACM0

# Project source directory
SOURCE_DIR = source

# Include directory
INCLUDE_DIR = include 

# Source files
SOURCE_FILES = \
    main.cpp \
	SevenSegment.cpp \
	Keypad.cpp \

BUILD_DIR = _build
BIN_DIR   = $(BUILD_DIR)/bin
OBJ_DIR   = $(BUILD_DIR)/obj

###
# Find include paths
INCLUDE_DIR := $(patsubst %,-I %,$(INCLUDE_DIR))

CC       = avr-gcc
OBJCOPY  = avr-objcopy 

CPPFLAGS = -Wall -Os -mmcu=$(MCU) -DF_CPU=$(CLOCK) $(INCLUDE_DIR)

all: $(PROGRAM_NAME)
$(PROGRAM_NAME): $(BIN_DIR)/$(PROGRAM_NAME).hex size

# obj <- cpp
.PRECIOUS: $(OBJ_DIR)/%.o 
$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp 
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CPPFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD_DIR)/*

# hex <- elf
$(BIN_DIR)/%.hex: $(BIN_DIR)/%.elf 
	$(OBJCOPY) -j .text -j .data -O ihex $^ $@

# elf <- obj
SOURCE_FILES := $(patsubst %.cpp,$(SOURCE_DIR)/%.cpp,$(SOURCE_FILES))
objects = $(patsubst $(SOURCE_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCE_FILES))

.PRECIOUS: $(BIN_DIR)/%.elf
$(BIN_DIR)/%.elf: $(objects)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CPPFLAGS) $^ -o $@

.PHONY: size

size:
	avr-size --format=avr --mcu=$(MCU) $(BIN_DIR)/$(PROGRAM_NAME).elf

flash:
	sudo avrdude -v -p$(MCU) -c$(PROGRAMMER) -P$(PORT) -b$(BAUD) -D -Uflash:w:$(BIN_DIR)/$(PROGRAM_NAME).hex:i