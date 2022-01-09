//#include "header.h"
#include "modify.h"
void modify()
{
	extern employee *first_node,*last_node;
	int exp=1;
	int choice;

	employee *modify_node=first_node;
	unsigned char entered_id[max_size],modify[max_size],reportee_display[max_size];
	unsigned register int i,reportee_count,flag=1;
	
	printf("Enter the Thundersoft Employee ID(Asociate code) to Modify the details\n");
	scanf("%s",entered_id);
	
	while(modify_node!=NULL){
		if(strlen(entered_id)==strlen(modify_node->id))
			if(strcmp(entered_id,modify_node->id)){
				modify_node=modify_node->next;
				continue;
			}
			else
				break;
		else
			modify_node=modify_node->next;
	}
	if(modify_node!=NULL){
		printf("%20s\t:\t\n","Details of the Employee");
		printf("%20s\t:\t%s\n",first_node->id,modify_node->id);
		printf("%20s\t:\t%s\n",first_node->name,modify_node->name);
		printf("%20s\t:\t%s\n",first_node->email,modify_node->email);
		printf("%20s\t:\t%s\n",first_node->band,modify_node->band);
		printf("%20s\t:\t%s\n",first_node->date,modify_node->date);
		printf("%20s\t:\t%s\n",first_node->mobile,modify_node->mobile);
		printf("%20s\t:\t%s\n",first_node->manager,modify_node->manager);
		
		reportee_count=0;
		strcpy(reportee_display,modify_node->reportees);
		char* token = strtok(reportee_display, "//");
		//printf("\t%s\n", token);
		while (token != NULL) {
			if(flag){
				printf("\t%s\n", token);
				flag=0;
				}
			else{
				printf("\t\t\t\t%s\n", token);	
			}
			token = strtok(NULL, "//");
		}
		printf("\n");
		printf("%20s\t:\t%s\n",first_node->techarea,modify_node->techarea);
		printf("%20s\t:\t%s\n",first_node->project,modify_node->project);
		printf("%20s\t:\t%s\n",first_node->status,modify_node->status);
		printf("%20s\t:\t%s\n",first_node->employee_relieving_date,modify_node->employee_relieving_date);
		printf("\n\n\n\n");
		
		
		
		while(exp)
			{       
			
				printf("\n\n\n\n\n");
				printf("1.Modify Name\n2.Modify Phone number\n3.Modify Reporting Manager Name\n4.Modify Band\n5.Modify Reportees\n6.Modify Tech Area\n7.Modify Project Info\n8.Exit\n");
				printf("Enter your choice : ");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1: 
					printf("Enter the name to modify\n");
					scanf("%[^\n]s",modify);
					strcpy(modify_node->name,modify);
					break;
			
					case 2:
					printf("Enter the phone number\n");
					scanf("%s",modify);
					strcpy(modify_node->mobile,modify);
					break;
			
					case 3: 
					printf("Enter the reporting manager name\n");
					scanf("%[^\n]s",modify);
					strcpy(modify_node->manager,modify);
					break;
			
					case 4: 
					printf("Enter the band\n");
					scanf("%s",modify);
					strcpy(modify_node->band,modify);
					break;
					
					case 5: 
					printf("\nEnter total no. of reporteees : ");
					int total_reportee;
					scanf("%d",&total_reportee);
					int i;
					for (i=0; i<total_reportee; i++)
					{
						char new_entry_reportee[max_size];
						getchar();
						printf("\nEnter Reportee Name and ID : ");
						scanf("%[^\n]s",new_entry_reportee);
						strcat(new_entry_reportee,"//");
						strcat(modify_node->reportees,new_entry_reportee);
					}
					modify_node->reportees[strlen(modify_node->reportees)-2] = '\0';
					break;
					
					case 6: 
					printf("Enter the tech area\n");
					scanf("%[^\n]s",modify);
					strcpy(modify_node->techarea,modify);
					break;
					
					case 7: 
					printf("project info\n");
					scanf("%[^\n]s",modify);
					strcpy(modify_node->project,modify);
					break;
			
					case 8:
					printf("Exiting from the Modify\n");
					exp=0;
					break;
			//exit(0);
			
					default :
					printf("Invalid Option -- Enter Your choice again\n");				
					break;
			
				}
			
			
			
			}
			
	}
	

	else
		printf("Employee ID doesn't exist\n");

	Start_Menu();
	//return;
}

