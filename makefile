CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS = main.o menu.o string_type.o field_info.o functions.o test.o
EXEC = main.exe

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

main.o: main.c menu.h functions.h test.h
	$(CC) $(CFLAGS) -c main.c

menu.o: menu.c menu.h 
	$(CC) $(CFLAGS) -c menu.c

string_type.o: string_type.c string_type.h
	$(CC) $(CFLAGS) -c string_type.c

field_info.o: field_info.c field_info.h
	$(CC) $(CFLAGS) -c field_info.c 

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

test.o: test.c test.h
	$(CC) $(CFLAGS) -c test.c

clean:
	del -f $(OBJS) $(EXEC)