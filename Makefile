CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGETS = ej1 ej2 ej3 ej5 
#TARGETS = malloc
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS)  $< -o $@

clean:	
	rm -f $(TARGETS)
	

.PHONY: all clean 	