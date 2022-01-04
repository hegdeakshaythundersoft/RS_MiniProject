#include "header.h"
 employee *first_node=NULL,*last_node=NULL;
void database_read(){
	
	unsigned register int i,j,reportee_count;
	signed char buffer[max_size],file_access,buffer_char,buf_char,buffer_max[max_size];
	FILE *fp_xls;
	employee *new_node=NULL;
	
	
	
	fp_xls=fopen("TSIndia_Emp_DB.xls","rb");
	
/*Linked List Creation*/
	
	//while(strcmp(buffer,"END_OF_FILE")){
	for(i=0;i<5;i++){
	new_node=(employee*)malloc(sizeof(employee));
	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->id,buffer);
	
	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->name,buffer);
	
	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->email,buffer);

	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->band,buffer);
	
	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->date,buffer);
	
	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->mobile,buffer);
	
	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->manager,buffer);

	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->reportees,buffer);
	
	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->techarea,buffer);
	
	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->project,buffer);

	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->status,buffer);
	
	fscanf(fp_xls,"%s",buffer);
	strcpy(new_node->employee_relieving_date,buffer);
	
		
	
	new_node->next=NULL;

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
	
	fp_txt=fopen("TSIndia_Emp_DB.xls","w");
	

	write_node=first_node;
	//for(i=0;(write_node!=NULL);i++){
	for(i=0;i<6;i++){
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
	fclose(fopen("fp_txt","wb"));
	fclose(fp_txt);
	return;
}	

/*Linked List Destruction*/
	/*free_node=first_node;
	while(free_node!=NULL){
	access_node=free_node;
	free_node=free_node->next;
	free(access_node);
	}*//*Linked List Destruction*/
	
	
	//printf("\n%s\n",first_node->id);
	
	
	
	/*fclose(fopen("base.xls","ab"));
	fclose(fp_txt);
	fp_txt=fopen("base.xls","rb");
	buf_char=fgetc(fp_txt);
	while(buf_char!=EOF){
	
	printf("%c",buf_char);
	buf_char=fgetc(fp_txt);
	
	}	
	

	fclose(fp_txt);
	return 0;



}*/
