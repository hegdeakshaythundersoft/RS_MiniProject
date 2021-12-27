#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


int main(){

	FILE *fp = fopen("sample_write_xlsx.xlsx","r");
	
	char line[200];
	
	while(fgets(line,200,fp)){
	
		char *token;
		int i=0;
		
		token = strtok(line,"\t");
		//printf("%s\n",token);
		while(token!=NULL){
			printf("%s ",token);
			token = strtok(NULL,"\t");
		}
		
		printf("\n");
	}
	
	return 0;
}
