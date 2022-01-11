//#include "header.h"
#include "delete.h"

const char *datestamp(){
			
	char *buffer = malloc(max_size);
	time_t t = time(NULL);
	struct tm  *tm;
	tm= localtime(&t); 
			  
	if ((tm->tm_hour) <12){
			  	
		sprintf(buffer,"%02d/%02d/%d", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900);
		//printf("%02d/%02d/%d %02d:%02d am", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900, tm->tm_hour, tm->tm_min);
	}
	else if ((tm->tm_hour)  == 12){
		sprintf(buffer,"%02d/%02d/%d", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900);
		//printf("%02d/%02d/%d %02d:%02d pm", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900, tm->tm_hour, tm->tm_min);
	}
	else{
		sprintf(buffer,"%02d/%02d/%d", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900);
		//printf("%02d/%02d/%d %02d:%02d pm", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900, (tm->tm_hour - 12), tm->tm_min);
	}
	
	return buffer;
}


void delete(){

	extern employee *first_node,*last_node;
	employee *delete_node=first_node;
	unsigned char entered_id[max_size],buf_char,reason_for_deletion[max_size];
	unsigned register int i,reportee_count;
	
	printf("Enter the Thundersoft Employee ID(Asociate code) to access the details for deletion\n");
	scanf("%s",entered_id);
	
	while(delete_node!=NULL){
		if(strlen(entered_id)==strlen(delete_node->id))
			if(strcmp(entered_id,delete_node->id)){
				delete_node=delete_node->next;
				continue;
			}
			else
				break;
		else
			delete_node=delete_node->next;
	}
	if(delete_node!=NULL){
	
		printf("%20s\t:\t\n","Details of the Employee to be deleted");
		view(delete_node);
		printf("\n\n\n\n");
		
		printf("Enter the reason for the deletion\n");
		scanf("%[^\n]s",reason_for_deletion);
		strcpy(delete_node->status,reason_for_deletion);
		strcpy(delete_node->employee_relieving_date,datestamp());		
		printf("\nEmployeee Deletion updated !!\n");
		view(delete_node);
		printf("\n\n\n\n");		
	}
	else
		printf("Employee ID doesn't exist\n");





	Start_Menu();
	//return;
}
