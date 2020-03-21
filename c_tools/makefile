CC=gcc
CFLAGS=-c -Wall 
LDFLAGS=
SRCS=fact.c main.c
OBJS=$(SRCS:.c=.o)
EXEC=factorial
message= Compiled Successfully

all: $(EXEC)
	@echo $(message)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -Wall -o $@
	@rm -f *.o

# .c.o: $(SRCS)
%.o:%.c
	$(CC) $(CFLAGS) $<

debug: CFLAGS +=-g
debug: message += For Debugging
debug: clean $(EXEC) 
	@mv $(EXEC) $(EXEC)_debug
	@echo $(message)
	@rm -f *.o

clean:
	@rm -f $(OBJS) $(EXEC) $(EXEC)_debug
	@echo "Project Cleaned."
