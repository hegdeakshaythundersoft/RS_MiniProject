/*
	
	Mini Project Structure	
	
*/
#include "header.h"

void Start_Menu(){

	printf("\nMain Menu\n");
	printf("1.Add\n2.Modify\n3.View\n4.Delete\n*.Exit\n");
	
	void (*func[4])();	// Array of Function Pointer
	func[0] = add;
	func[1] = modify;
	func[2] = view;
	func[3] = delete;
	
	char action;
	
	//getchar();
	scanf(" %c",&action);
	switch(action){
		
		case '1': 
			func[0]();
			break;
			
		case '2': 
			func[1]();
			break;
			
		case '3': 
			func[2]();
			break;
			
		case '4': 
			func[3]();
			break;
			
		case '*':
			printf("Exiting from the Program \n");
			break;
			//exit(0);
			
		default :
			printf("Invalid Option -- Enter Your Responsse again\n");
			Start_Menu();
		}
	
	}
	
void main(){

	printf("In Main Function : \n");
	
	//Initialise Start Menu Function
	Start_Menu();
	printf("Exited from the program\n");
	
}
