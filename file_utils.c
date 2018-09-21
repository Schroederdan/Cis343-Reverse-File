#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "file_utils.h"

/* Read and write to and from a file */

/* Reads in a file
* char* filename - the pointer to the file to be opened
* char** buffer - the location that the read in data will be saved
* return last_pos - the bit number of the last bit
*/
int read_file(char* filename, char** buffer) {
	//open file (argv[1]) in read mode
	FILE* fp;
	fp = fopen(filename,"r");
	
	long last_pos;

	if(fp==NULL){
		printf("Failed to open the file");
		return -1;
	}else{
		fseek(fp,-1L,2);
		//save last_pos as the number of bits that were counted
		last_pos = ftell(fp);
		last_pos++;
		//return to beginning of file
		rewind(fp);

		//allocate space in memory for the file to be saved
		*buffer = malloc(sizeof(char) * (last_pos));
		fread(*buffer,sizeof(char),last_pos,fp);
		
		//close the file
		fclose(fp);
	}

	return last_pos;
}

/* Write out to a file
* char* filename - Where the file is going to be saved
* char *buffer - what were going to put in the file
* int size - size of buffer / how much space the file needs
*/
int write_file(char* filename, char* buffer, int size){
	//open the file (argv[2]) in write mode
	FILE* fp = fopen(filename,"w");
	
	if(fp==NULL){
		printf("Failed to open the file");
		return -1;
	}else{	
		//write buffer to the file
		fwrite(buffer,sizeof(char),size,fp);
	}
	return 0;
}
