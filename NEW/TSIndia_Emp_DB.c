//#include "header.h"
#include "TSIndia_Emp_DB.h"
employee *first_node=NULL,*last_node=NULL;
unsigned int total_nodes = 0;

void database_read(){
	
	extern unsigned int total_nodes;
	
	unsigned register int i,j,reportee_count;
	signed char buffer[max_size],buffer1[max_size],buffer2[max_size],buffer3[max_size],buffer4[max_size],buffer5[max_size],buffer6[max_size],buffer7[max_size],buffer8[max_size],buffer9[max_size],buffer10[max_size],buffer11[max_size];

	FILE *fp_xls;
	employee *new_node=NULL;
	
	
	
	fp_xls=fopen("TSIndia_DB.xlsx","r");
	//fp_xls=fopen("TSIndia_Emp_DB.xlsx","r");
	
	total_nodes = 0;
	printf("Im in database Read section\n");
	while(fscanf(fp_xls,
		"%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\n]%*c",
		buffer,
		buffer1,
		buffer2,
		buffer3,
		buffer4,
		buffer5,
		buffer6,
		buffer7,
		buffer8,
		buffer9,
		buffer10,
		buffer11
	)!=EOF)
{
	new_node=(employee*)malloc(sizeof(employee));

	strcpy(new_node->id,buffer);

	strcpy(new_node->name,buffer1);

	strcpy(new_node->email,buffer2);

	strcpy(new_node->band,buffer3);

	strcpy(new_node->date,buffer4);

	strcpy(new_node->mobile,buffer5);
	
	strcpy(new_node->manager,buffer6);

	strcpy(new_node->reportees,buffer7);
	

	strcpy(new_node->techarea,buffer8);
	

	strcpy(new_node->project,buffer9);


	strcpy(new_node->status,buffer10);
	
	strcpy(new_node->employee_relieving_date,buffer11);
	
	total_nodes+=1;
	
	new_node->next=NULL;
	
	//struct_id[i] = new_node;
	
	if(first_node==NULL)
		first_node=last_node=new_node;
	else{
	
		last_node->next=new_node;
		last_node=new_node;
	
	}
	}

	fclose(fp_xls);
	
	return;
}
		
void database_write(){
	
	extern unsigned int total_nodes;
	
	unsigned register int i,j,reportee_count;
	signed char buffer[max_size],file_access,buffer_char,buf_char,buffer_max[max_size];
	FILE *fp_txt;
	employee *access_node=NULL,*write_node=NULL;
	
	if (remove("TSIndia_DB.xlsx") == 0){
		printf("New File Created\n\n");
	}
	
	fp_txt=fopen("TSIndia_DB.xlsx","a");
	//fp_txt=fopen("TSIndia_Emp_DB.xlsx","a");
	
	write_node=first_node;

	for(i=0;i<total_nodes;i++){
	strcpy(buffer,"\0");
	
	strcpy(buffer,write_node->id);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->name);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->email);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->band);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->date);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->mobile);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->manager);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->reportees);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->techarea);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->project);
	fprintf(fp_txt,"%s\t",buffer);
	
	
	strcpy(buffer,write_node->status);
	fprintf(fp_txt,"%s\t",buffer);
	
	strcpy(buffer,write_node->employee_relieving_date);
	fprintf(fp_txt,"%s\n",buffer);
	
	
	access_node=write_node;
	write_node=write_node->next;
	free(access_node);

	
}
	fclose(fp_txt);
	return;
}	
