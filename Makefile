CC = g++
CFLAGS = -g -Wall -std=c++17
TARGET = GraphBuilder
all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp Graph.cpp Node.cpp 
clean:
	$(RM) $(TARGET)
