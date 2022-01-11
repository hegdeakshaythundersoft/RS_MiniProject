/*	
	Add Employee Details to Excel Sheet
	
	Execute :
		make 
*/

//#include "header.h"
#include "add.h"
const char *timestamp(){
			
	char *buffer = malloc(max_size);
	time_t t = time(NULL);
	struct tm  *tm;
	tm= localtime(&t); 
			  
	if ((tm->tm_hour) <12){
			  	
		sprintf(buffer,"%02d/%02d/%d %02d:%02d am", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900, tm->tm_hour, tm->tm_min);
		//printf("%02d/%02d/%d %02d:%02d am", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900, tm->tm_hour, tm->tm_min);
	}
	else if ((tm->tm_hour)  == 12){
		sprintf(buffer,"%02d/%02d/%d %02d:%02d pm", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900, tm->tm_hour, tm->tm_min);
		//printf("%02d/%02d/%d %02d:%02d pm", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900, tm->tm_hour, tm->tm_min);
	}
	else{
		sprintf(buffer,"%02d/%02d/%d %02d:%02d pm", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900, (tm->tm_hour - 12), tm->tm_min);
		//printf("%02d/%02d/%d %02d:%02d pm", tm->tm_mday , tm->tm_mon + 1, tm->tm_year+ 1900, (tm->tm_hour - 12), tm->tm_min);
	}
	
	return buffer;
}


void add()
{
	extern employee *first_node,*last_node;
	printf("Performing Add Operation\n");
	employee *add_node;
	add_node = malloc(sizeof(employee));
	
	printf("\nEnter Employee ID : ");
	scanf("%s",add_node->id);
	//strcat(add_node->id,"\t");
	
	printf("\nEnter Name of the Employee : ");
	getchar();
	scanf("%[^\n]s",add_node->name);
	//strcat(add_node->name,"\t");
	
	printf("\nEnter Employee Email ID : ");
	scanf("%s",add_node->email);
	//strcat(add_node->email,"\t");
	
	printf("\nEnter Band : ");
	scanf("%s",add_node->band);
	//strcat(add_node->band,"\t");
	
	printf("\nEnter Date of Joining : ");
	scanf("%s",add_node->date);
	//strcat(add_node->date,"\t");
	
	printf("\nEmployee Mobile Number : ");
	scanf("%s",add_node->mobile);
	//strcat(add_node->mobile,"\t");
	
	printf("\nEnter Detials of reporting Manager : ");
	getchar();
	scanf("%[^\n]s",add_node->manager);
	//strcat(add_node->manager,"\t");
	
	
	char repo;
	
	//char totalreportees[max_size]="";
	printf("\nAny Reportees working under you : Yes(Y)/No(N) : ");
	scanf(" %c",&repo);
	
	if (repo == 'Y'){
		
		
		printf("\nEnter total no. of reporteees : ");
		int total_reportee;
		scanf("%d",&total_reportee);
		int i;
		for (i=0; i<total_reportee; i++){
			char new_entry_reportee[max_size];
			getchar();
			printf("\nEnter Reportee Name and ID : ");
			scanf("%[^\n]s",new_entry_reportee);
			strcat(new_entry_reportee,"//");
			strcat(add_node->reportees,new_entry_reportee);
		}
		add_node->reportees[strlen(add_node->reportees)-2] = '\0';
	}
	
	else{
		strcpy(add_node->reportees,"NA");
	}
	
	//strcat(add_node->totalreportees,"\t");
		
	printf("\nEnter Tech Area of Employee : ");
	scanf("%s",add_node->techarea);
	//strcat(add_node->techarea,"\t");
	
	
	printf("\nProject Information : ");
	getchar();
	scanf("%[^\n]s",add_node->project);
	//strcat(add_node->project,"\t");
	
	
	strcpy(add_node->status,"Active");			//implicit initialisation
	//strcat(add_node->status,"\t");
	
	strcpy(add_node->employee_relieving_date,"NA");	//implicit initialisation
	//strcat(add_node->employee_relieving_date,"\n");
	
	printf("Employee Successfully added : \n");
	view(add_node);
	
	extern unsigned int total_nodes;
	total_nodes+=1;
	add_node->next=NULL;
	last_node->next=add_node;
	last_node=add_node;
	
	Start_Menu();
}
