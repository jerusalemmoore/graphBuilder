CC = g++
CFLAGS = -g -Wall -std=c++17
TARGET = Node
all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp main.cpp

clean:
	$(RM) nodeProg
