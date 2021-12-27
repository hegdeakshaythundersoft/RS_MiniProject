/*
	
	Mini Project Structure	
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <header.h>

/*
typedef struct reporteee{
	const int ID;
	unsigned char *NAME;
}Reportee;


typedef struct employee_data{

	const int ID;
	unsigned char *NAME;
	const unsigned char *EMAIL;
	unsigned char *BAND;
	const unsigned char *DATE;
	unsigned int MOBILE;
	unsigned char *MANAGER;
	
	Reportee *reportees;	// nested struct
	
	//unsigned char *Reportees; // nested struct
	
	unsigned char *TechArea;
	unsigned char *Project;
}EMP;
*/
int main(){

	void (*func[4])();	// Array of Function Pointer

	// All functions are from different files
	
	func[0] = add();	
	func[1] = modify();	
	func[2] = display();	
	func[3] = delete();	
	
	EMP *head = malloc(sizeof(EMP));
	EMP head;
	int *p;
	p = (int*)&head->ID;
	*p = 45;
	printf("ID of the Employee = %d\n",head->ID);
	
}
