all: clean
	gcc linked_list6.c print.c -o output

clean:
	rm -f main