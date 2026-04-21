CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all:
	$(CC) main.c menu.c student.c -o app $(CFLAGS)
	@echo "Build successful"

run:
	@./app

 clean:
	rm -f app