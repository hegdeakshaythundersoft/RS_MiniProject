employee : main.o add.o modify.o view.o delete.o TSIndia_Emp_DB.o
	gcc -g main.c add.c modify.c view.c delete.c TSIndia_Emp_DB.c -o $@
%o:	%.o
	gcc -c $<	
clean:
	rm -f employee
	rm -f *.o
