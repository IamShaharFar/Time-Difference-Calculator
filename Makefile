# Makefile for compiling time_diff program

CC = gcc
CFLAGS = -ansi -pedantic -Wall
TARGET = timediff
SRCS = timediff.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)