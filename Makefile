CC = g++
CFLAGS = -g -Wall -std=c++17
TARGET = Graph
all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp Node.cpp main.cpp

clean:
	$(RM) $(TARGET)
