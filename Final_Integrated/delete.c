#include "header.h"
void delete(){

	extern employee *first_node,*last_node;
	employee *delete_node=first_node;
	unsigned char entered_id[max_size],buf_char,reason_for_deletion[max_size];
	unsigned register int i,reportee_count;
	
	printf("Enter the Thundersoft Employee ID(Asociate code) to access the deatails for deletion\n");
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
		printf("%20s\t:\t%s\n",first_node->id,delete_node->id);
		printf("%20s\t:\t%s\n",first_node->name,delete_node->name);
		printf("%20s\t:\t%s\n",first_node->email,delete_node->email);
		printf("%20s\t:\t%s\n",first_node->band,delete_node->band);
		printf("%20s\t:\t%s\n",first_node->date,delete_node->date);
		printf("%20s\t:\t%s\n",first_node->mobile,delete_node->mobile);
		printf("%20s\t:\t%s\n",first_node->manager,delete_node->manager);
		
		/*reportee_count=0;
		for(i=0;i<max_size;i++){
			buf_char=delete_node->reportees[i];
			
			if(buf_char==';'){
				printf("\n%20s[%d]\t:\t",first_node->reportees,1+reportee_count++);
				continue;	
			}
			else if(i==0)
				printf("%20s[%d]\t:\t",first_node->reportees,1+reportee_count++);
			printf("%c",buf_char);
		}
		printf("\n");*/
		printf("%20s\t:\t%s\n",first_node->techarea,delete_node->techarea);
		printf("%20s\t:\t%s\n",first_node->project,delete_node->project);
		printf("%20s\t:\t%s\n",first_node->status,delete_node->status);
		printf("%20s\t:\t%s\n",first_node->employee_relieving_date,delete_node->employee_relieving_date);
		printf("\n\n\n\n");
		printf("Enter the reason for the deletion\n");
		scanf("%s",reason_for_deletion);
		strcpy(delete_node->status,reason_for_deletion);			
	}
	

	else
		printf("Employee ID doesn't exist\n");





	Start_Menu();
	//return;
}
