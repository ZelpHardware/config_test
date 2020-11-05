#include "Example.h"

#include <string.h>

// This file is here so that the starter project can create a library with it.
// Delete it once your own production code is under test

int example(void)
{
	return 1;
}



uint16_t config_parse(char* buffer)
{
	if(strlen(buffer) < 1)
		return ZELP_FAIL;
	else
	{
		return ZELP_SUCCESS;
	}
	

}