all: clean
	gcc stack3.c print.c -o output

clean:
	rm -f main