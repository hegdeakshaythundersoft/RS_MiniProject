#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *fptr;
	fptr = fopen("sample_write_xlsx.xlsx","a");
	
	char ch, name[20]="HELLO";
	int id = 20;
	
	fprintf(fptr,"ID\tName\n");
	
	fprintf(fptr,"%d\t%s\n",id,name);
	
	fclose(fptr);
	
	return 0;
}
