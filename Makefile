# Makefile for compiling time_diff program

CC = gcc
CFLAGS = -ansi -pedantic -Wall
TARGET = timediff

$(TARGET): timediff.c timediff.h
	$(CC) $(CFLAGS) -o $(TARGET) timediff.c

clean:
	rm -f $(TARGET)