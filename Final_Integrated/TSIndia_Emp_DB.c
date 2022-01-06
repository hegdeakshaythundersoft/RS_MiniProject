//#include "header.h"
#include "TSIndia_Emp_DB.h"
employee *first_node=NULL,*last_node=NULL;
 
void database_read(){
	
	unsigned register int i,j,reportee_count;
	signed char buffer[max_size],file_access,buffer_char,buf_char,buffer_max[max_size];
	FILE *fp_xls;
	employee *new_node=NULL;
	
	
	
	fp_xls=fopen("TSIndia_Emp_DB.xlsx","r");
	
/*Linked List Creation*/
	
	//while(strcmp(buffer,"END_OF_FILE")){
	for(i=0;i<280;i++){
	new_node=(employee*)malloc(sizeof(employee));
	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->id,buffer);
	
	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->name,buffer);
	
	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->email,buffer);

	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->band,buffer);
	
	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->date,buffer);
	
	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->mobile,buffer);
	
	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->manager,buffer);

	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->reportees,buffer);
	
	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->techarea,buffer);
	
	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->project,buffer);

	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\t]%*c",buffer);
	strcpy(new_node->status,buffer);
	
	//fscanf(fp_xls,"%s",buffer);
	fscanf(fp_xls,"%[^\n]%*c",buffer);
	strcpy(new_node->employee_relieving_date,buffer);
	
		
	
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
	
	
	
	unsigned register int i,j,reportee_count;
	signed char buffer[max_size],file_access,buffer_char,buf_char,buffer_max[max_size];
	FILE *fp_txt;
	employee *access_node=NULL,*write_node=NULL;
	
	if (remove("TSIndia_Emp_DB.xlsx") == 0){
		printf("New File Created\n\n");
	}
	
	fp_txt=fopen("TSIndia_Emp_DB.xlsx","a");
	
	/*
	fprintf(fp_txt,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n","Associate_Code","Associate_Name","Email","Department","Date_Of_Joining",
	"Phone_no.","Reporting_Manager","reportees","Tech_area","Project_info","Status","Relieving_Date");
	*/
	
	write_node=first_node;
	//for(i=0;(write_node!=NULL);i++){
	for(i=0;i<281;i++){
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
	
	//fprintf(fp_txt,"%s","\n");
	
	
	access_node=write_node;
	write_node=write_node->next;
	free(access_node);

	
}
	//fclose(fopen("fp_txt","wb"));
	fclose(fp_txt);
	return;
}	
