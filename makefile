CC = gcc
TARGET = rrc
SRCS = rrc.c utils/server.c utils/client.c utils/message-handler.c
OBJS = $(SRCS:.c=.o)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm **/*.o

clean : 
	rm **/*.o $(TARGET)
