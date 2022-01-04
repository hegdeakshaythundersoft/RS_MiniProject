#include "header.h"

void view(){

	extern employee *first_node,*last_node;
	employee *view_node=first_node;
	
	unsigned char entered_id[max_size],buf_char;
	unsigned register int i,reportee_count;
	
	printf("Enter the Thundersoft Employee ID(Asociate code) to access the deatails\n");
	scanf("%s",entered_id);
	
	while(view_node!=NULL){
		if(strlen(entered_id)==strlen(view_node->id))
			if(strcmp(entered_id,view_node->id)){
				view_node=view_node->next;
				continue;
			}
			else
				break;
		else
			view_node=view_node->next;
	}
	if(view_node!=NULL){
		printf("%20s\t:\t%s\n",first_node->id,view_node->id);
		printf("%20s\t:\t%s\n",first_node->name,view_node->name);
		printf("%20s\t:\t%s\n",first_node->email,view_node->email);
		printf("%20s\t:\t%s\n",first_node->band,view_node->band);
		printf("%20s\t:\t%s\n",first_node->date,view_node->date);
		printf("%20s\t:\t%s\n",first_node->mobile,view_node->mobile);
		printf("%20s\t:\t%s\n",first_node->manager,view_node->manager);
		
		/*reportee_count=0;
		for(i=0;i<max_size;i++){
			buf_char=view_node->reportees[i];
			
			if(buf_char==';'){
				printf("\n%20s[%d]\t:\t",first_node->reportees,1+reportee_count++);
				continue;	
			}
			else if(i==0)
				printf("%20s[%d]\t:\t",first_node->reportees,1+reportee_count++);
			printf("%c",buf_char);
		}
		printf("\n");*/
		printf("%20s\t:\t%s\n",first_node->techarea,view_node->techarea);
		printf("%20s\t:\t%s\n",first_node->project,view_node->project);
		printf("%20s\t:\t%s\n",first_node->status,view_node->status);
		printf("%20s\t:\t%s\n",first_node->employee_relieving_date,view_node->employee_relieving_date);
		printf("\n\n\n\n");
		view_node=view_node->next;	
	}
	

	else
		printf("Employee ID doesn't exist\n");
	Start_Menu();
	//return;

}



