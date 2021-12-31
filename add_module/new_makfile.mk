employee : main.o add_alternate_files.o modify.o view.o delete.o
	gcc main.c add_alternate_files.c modify.c view.c delete.c -o $@
	
add_alternate_files.o:	add_alternate_files.c
	gcc -c add_alternate_files.c

modify.o : modify.c
	gcc -c modify.c

view.o : view.c
	gcc -c view.c

delete.o : delete.c
	gcc -c delete.c
clean:
	rm -f employee
	rm -f *.o
