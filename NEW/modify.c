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
		view(modify_node);
		
		while(exp)
			{       
			
				printf("\n\n\n");
				printf("1.Modify Name\n2.Modify Phone number\n3.Modify Reporting Manager Name\n4.Modify Band\n5.Modify Reportees\n6.Modify Tech Area\n7.Modify Project Info\n8.Exit\n");
				printf("Enter your choice : ");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1: 
					printf("\nEnter name to modify : ");
					getchar();
					scanf("%[^\n]s",modify);
					strcpy(modify_node->name,modify);
					printf("Name Modified !!\n");
					break;
			
					case 2:
					printf("\nEnter phone number : ");
					scanf("%s",modify);
					strcpy(modify_node->mobile,modify);
					printf("\nPhone Number Modified !!\n");
					break;
			
					case 3: 
					printf("\nEnter the reporting manager name : ");
					getchar();
					scanf("%[^\n]s",modify);
					strcpy(modify_node->manager,modify);
					printf("Reporting Manager details Modified !!\n");
					break;
			
					case 4: 
					printf("\nEnter the band : ");
					scanf("%s",modify);
					strcpy(modify_node->band,modify);
					printf("Employee Band Modified !!\n");
					break;
					
					case 5: 
					printf("\nEnter total no. of reporteees : ");
					strcat(modify_node->reportees,"//");
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
					printf("Employee Reportees Modified !!\n");
					break;
					
					case 6: 
					printf("\nEnter the tech area : ");
					getchar();
					scanf("%[^\n]s",modify);
					strcpy(modify_node->techarea,modify);
					printf("\nEmployee Tech Area Modified !!\n");
					break;
					
					case 7: 
					printf("\nProject Info : ");
					getchar();
					scanf("%[^\n]s",modify);
					strcpy(modify_node->project,modify);
					printf("Employee Project Information Modified !!\n");
					break;
			
					case 8:
					printf("\nAfter Modifying Employee Details : \n");
					view(modify_node);
					exp=0;
					printf("Exiting from the Modify\n");
					break;
			
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

