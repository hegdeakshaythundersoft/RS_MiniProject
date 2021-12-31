/*	
	Add Employee Details to Excel Sheet
	
	Execute :
		make 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
#define max_size 1000
#pragma pack(1)

/*

As of now not needed

struct reportee{

	char id[max_size];
	char name[max_size];
	
};
 
*/
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
	struct employee *s1;
	s1 = malloc(sizeof(struct employee));
	
	FILE *fp1;
	
	printf("\nEnter Employee ID : ");
	scanf("%s",s1->id);
	
	printf("\nEnter Name of the Employee : ");
	getchar();
	scanf("%[^\n]s",s1->name);
	
	printf("\nEnter Employee Email ID : ");
	scanf("%s",s1->email);
	
	printf("\nEnter Band : ");
	scanf("%s",s1->band);
	
	printf("\nEnter Date of Joining : ");
	scanf("%s",s1->date);
	
	printf("\nEmployee Mobile Number : ");
	scanf("%s",s1->mobile);
	
	printf("\nEnter Detials of reporting Manager : ");
	getchar();
	scanf("%[^\n]s",s1->manager);
	
	char repo;
	char totalreportees[max_size]="";
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
			strcat(new_entry_reportee,"/");
			strcat(totalreportees,new_entry_reportee);
		}
		totalreportees[strlen(totalreportees)-1] = '\0';
	}
	
	else{
		strcpy(totalreportees,"NA");
	}
		
	printf("\nEnter Tech Area of Employee : ");
	scanf("%s",s1->techarea);
	
	printf("\nProject Information : ");
	getchar();
	scanf("%[^\n]s",s1->project);
	
	
	strcpy(s1->status,"Active");	//implicit initialisation
	strcpy(s1->employee_relieving_date,"");	
	
	fp1 = fopen("sample_data.xlsx","a");
	
	strcpy(s1->date_employee_created,timestamp());

	fprintf(
		fp1,
		"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		s1->id,
		s1->name,
		s1->email,
		s1->band,
		s1->date,
		s1->date_employee_created,
		s1->mobile,
		s1->manager,
		s1->techarea,
		s1->project,
		s1->status,
		totalreportees,
		s1->employee_relieving_date
	);
	
	fclose(fp1);
	free(s1);
}


int main(){

	printf("Insert Thudersoft Employee Details\n");
	add();
	return 0;
}
