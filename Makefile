CC = g++

CFlags = -g -wall

TARGET = rayt

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o:
	$(CC) $(CFLAGS) -c src/main.cpp

clean:
	rm -rf *.o
	rm -f $(TARGET)
