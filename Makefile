CC = clang

TARGET = NumberGuessingGame

all: $(TARGET)

$(TARGET): main.c
	$(CC) -o $(TARGET) main.c

clean:
	rm -f $(TARGET)