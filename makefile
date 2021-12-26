all: clean
	gcc queue3.c print.c -o output

clean:
	rm -f main