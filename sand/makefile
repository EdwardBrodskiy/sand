CC=g++
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
TARGET=main
LDFLAGS= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $<

clean:
	rm *.o main

run:
	./main
