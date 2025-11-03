EXECUTABLE = RPGGamee
CC = g++
CFLAGS = -Wall -g -std=c++11
SOURCES = main.cpp Armor.cpp Item.cpp Player.cpp Potion.cpp Weapon.cpp
OBJECTS = $(SOURCES:.cpp=.o)
 
.PHONY: all
all: $(EXECUTABLE)
 
$(EXECUTABLE): $(OBJECTS)
				$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)
 
%.o: %.cpp
				$(CC) $(CFLAGS) -c $< -o $@
 
.PHONY: clean
clean:
				rm -f $(OBJECTS) $(EXECUTABLE)