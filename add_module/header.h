/*
	
	Header File
	
*/

#ifndef  headers 		// Maintains Single Copy 

#define headers
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h> 
	#include <time.h>
	
	#define max_size 1000
	#pragma pack(1)

	struct employee
	{
		char id[max_size];
		char name[max_size];
		char email[max_size];
		char band[max_size];
		char date[max_size];
		char date_employee_created[max_size];		// employee details added
		char mobile[max_size]; 
		char manager[max_size];
		char techarea[max_size];
		char project[max_size];	
		char status[max_size];
		char employee_relieving_date[max_size];	// employee relieving date
	};
	
void Start_Menu();
void add();
void delete();
void modify();
void view();

#endif
