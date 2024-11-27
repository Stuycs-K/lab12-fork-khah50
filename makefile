.PHONY: clean run compile

compile: main.o fork.o
	@gcc -o runme main.o fork.o -Wall

main.o: main.c fork.h
	@gcc -c main.c -Wall

fork.o: fork.c fork.h
	@gcc -c fork.c -Wall

run: compile
	@./runme

clean:
	rm -f *.o runme
