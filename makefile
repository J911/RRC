CC = gcc
TARGET = rrc
SRCS = rrc.c server.c
OBJS = $(SRCS:.c=.o)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm *.o

clean : 
	rm *.o $(TARGET)
