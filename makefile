all: clean
	gcc linked_list4.c print.c -o output

clean:
	rm -f main