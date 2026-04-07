CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGETS = ej1 
#TARGETS = malloc
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS)  $< -o $@

clean:	
	rm -f $(TARGETS)
	

.PHONY: all clean 	