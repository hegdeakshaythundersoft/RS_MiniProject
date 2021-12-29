/*	
	Add Employee Details to Excel Sheet
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
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
	char mobile[max_size]; 
	char manager[max_size];
	char techarea[max_size];
	char project[max_size];	
	char status[max_size];
};

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
			strcat(new_entry_reportee,"&");
			strcat(totalreportees,new_entry_reportee);
		}
	}
	
		
	printf("\nEnter Tech Area of Employee : ");
	scanf("%s",s1->techarea);

	
	printf("\nProject Information : ");
	getchar();
	scanf("%[^\n]s",s1->project);
	
	
	strcpy(s1->status,"Active");	//implicit initialisation
	
	fp1 = fopen("sample_data.xlsx","a");
	
	fprintf(
		fp1,
		"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		s1->id,
		s1->name,
		s1->email,
		s1->band,
		s1->date,
		s1->mobile,
		s1->manager,
		s1->techarea,
		s1->project,
		s1->status,
		totalreportees
	);
	
	fclose(fp1);
	free(s1);
}


int main(){

	printf("Insert Thudersoft Employee Details\n");
	add();
	return 0;
}
