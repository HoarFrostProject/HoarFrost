# Set up basic variables:
CC = g++
CFLAGS = -c -Wall
LDFLAGS =

# List of sources:
SOURCES = helloworld.c
OBJECTS = $(SOURCES:.c=.o)

# Name of executable target:
EXECUTABLE = helloworld

CFLAGS += `pkg-config --cflags gtk+-3.0`
LDFLAGS += `pkg-config --libs gtk+-3.0`

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)