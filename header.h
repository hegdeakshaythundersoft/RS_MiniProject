/*
	Header File
*/


#ifndef  headers 		// Maintains Single Copy 

#define headers

	void add(); 		// add data to excel sheet
	void modify();		// modify data and update from excel sheet
	void display();	// display the data from excel sheet
	void delete();		// delete data from excel sheet

	// if employee having any reportees
	typedef struct reporteee{
		const int ID;
		unsigned char *NAME;
	}Reportee;

	// Employee Data Strucutre
	typedef struct employee_data{

		//const int ID;
		const char ID[7];
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

#endif
