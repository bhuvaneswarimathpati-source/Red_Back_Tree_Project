CC = gcc

CFLAGS = -Wall -Wextra -g

TARGET = rbt

SRCS = main.c \
       insert.c \
       insert_fix.c \
       delete.c \
       delete_fixup.c \
       delete_min.c \
       delete_max.c \
       rotate.c \
       find_min.c \
       find_max.c \
       display.c \
       validate.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c main.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)