# Set up basic variables:
CC = g++
CFLAGS = -c -Wall
LDFLAGS =

# List of sources:
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

# Name of executable target:
EXECUTABLE = main

LDFLAGS += -lglut -lGLU -lGL

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)