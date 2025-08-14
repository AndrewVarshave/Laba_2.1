CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS = main.o menu.o string.o
EXEC = main.exe

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

   main.o: main.c menu.h
	$(CC) $(CFLAGS) -c main.c

   menu.o: menu.c menu.h string.h
	$(CC) $(CFLAGS) -c menu.c

   string.o: string.c string.h
	$(CC) $(CFLAGS) -c string.c

   clean:
	del -f $(OBJS) $(EXEC)