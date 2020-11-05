#include "Example.h"

#include <string.h>
#include <stdio.h>
// This file is here so that the starter project can create a library with it.
// Delete it once your own production code is under test

int example(void)
{
	return 1;
}



uint16_t config_parse(char* buffer)
{
	char endOfLine= buffer[strlen(buffer)-1];
	// printf("received buffer %c\n",endOfLine);
	// printf("sizeof(buffer) = %ld sizeof(0) = %ld\n",sizeof(buffer),sizeof(0));
	// printf("strlen(file_name)-1 %ld\n",strlen(buffer)); 
	if(strlen(buffer) < 1 || endOfLine != '\n')
		return ZELP_BAD_RESPONSE;
	else
	{
		return ZELP_SUCCESS;
	}
	

}