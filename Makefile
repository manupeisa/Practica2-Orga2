CC = gcc
CFLAGS =-Wall -Wextra -pedantic 
TARGETS = ej1 ej2 ej3 ej5 ej6 ej7 ej8 ej9 ej10 ej11 ej11funcional ej12 ej13 ej14 ej15 ej16 ej17 ej18 ej19
#TARGETS = malloc
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS)  $< -o $@

clean:	
	rm -f $(TARGETS)
	

.PHONY: all clean 	