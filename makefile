OBJ:=$(patsubst %.c,%.o,$(wildcard *.c))
main.exe:$(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
