EXECUTABLE = game
CC = g++
CFLAGS = -Wall -g -std=c++11
SOURCES = main.cpp Armor.cpp Item.cpp Player.cpp Potion.cpp Weapon.cpp
OBJDIR = build
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

TARGET = $(OBJDIR)/$(EXECUTABLE)
 
.PHONY: all
all: $(TARGET)
 
$(TARGET): $(OBJECTS)
				$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)
 
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean
clean:
				rm -rf $(OBJECTS)