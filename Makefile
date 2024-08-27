CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = syscheck

all: $(TARGET)

$(TARGET): main.o cpu.o memory.o disk.o kernel.o uptime.o processes.o network.o utils.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o cpu.o memory.o disk.o kernel.o uptime.o processes.o network.o utils.o

main.o: main.c cpu.h memory.h disk.h kernel.h uptime.h processes.h network.h utils.h
	$(CC) $(CFLAGS) -c main.c

cpu.o: cpu.c cpu.h utils.h
	$(CC) $(CFLAGS) -c cpu.c

memory.o: memory.c memory.h utils.h
	$(CC) $(CFLAGS) -c memory.c

disk.o: disk.c disk.h utils.h
	$(CC) $(CFLAGS) -c disk.c

kernel.o: kernel.c kernel.h utils.h
	$(CC) $(CFLAGS) -c kernel.c

uptime.o: uptime.c uptime.h utils.h
	$(CC) $(CFLAGS) -c uptime.c

processes.o: processes.c processes.h utils.h
	$(CC) $(CFLAGS) -c processes.c

network.o: network.c network.h utils.h
	$(CC) $(CFLAGS) -c network.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o $(TARGET)

