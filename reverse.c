#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/////////////////////////////////////////////////////
//Daniel Schroeder
//Cis 343 Project 1
//
//The goal of this project is to open a file reverse the data
//and save it to another file
//
//Proper calling of this file is ./reverse <FileIn> <FileOut>
////////////////////////////////////////////////////

int main(int argc,char** argv){
	//if not proper inputs error out
	if(argc != 3){
		printf("Proper call is ./reverse <FileIn> <FileOut>");
		return -1;
	}

	//file to be read in
	char* readFile = argv[1];
	//file to be saved to
	char* writeFile = argv[2];
	//location in memory to recieve the data that is in the read file
	char* buffer;

	//open the file and pull the data
	int size = read_file(readFile, &buffer);

	//size returns -1 only if theres an error opening
	if(size == -1){
		printf("Error opening file");
		return -1;
	}

	//dedicate more memory to collect the data from buffer but in reverse order
	char* rmemloc = malloc(size * sizeof(char));

	//flip buffer into rmemloc
	for(int i=0; i<size;i++){
		rmemloc[i] = *(buffer + size - 1 - i);
	}

	//n is a variable created just to make sure write_file does not return -1 / error out
	int n = write_file(writeFile, rmemloc, size);
	if(n == -1){
		printf("error opening write file");
		return -1;
	}

	//clean up space in memory
	free(rmemloc);
	free(buffer);

	return 0;
}	
