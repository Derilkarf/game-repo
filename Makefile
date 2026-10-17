CC = gcc

CFLAGS = -Wall -Wextra 

LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET = game

all: $(TARGET)

$(TARGET): game.c

	$(CC) $(CFLAGS) game.c -o $(TARGET) $(LIBS)

clean:

	rm -r $(TARGET)
