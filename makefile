CC=g++
CFLAGS=-c -Wall -g
SDLFLAGS=`sdl-config --cflags --libs` -framework SDL2 -framework Cocoa
SOURCES= movable.cpp actor.cpp level.cpp player.cpp test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ProbeGame.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(SDLFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
