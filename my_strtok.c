#include <string.h>
#include <stdio.h>

char*	my_strtok(char *str, char *c)
{

	if(!c || c == "")
		return NULL;

	static char *buffer = NULL;

	if(str)
		buffer = str;
	else
		if(!buffer || !*buffer)
			return NULL;

	int i = 0;
	int len = strlen(c);

	while(*buffer && *buffer == *c) 
		buffer += 1;

	char *token = buffer;

	while(*buffer && i != len)
	{
		i = 0;


		while(*buffer && *buffer != *c)
			buffer += 1;
		
		while(buffer[i] == c[i] && i < len)
			i += 1;
		
		if(i == len){
			*buffer = 0;
			buffer += len;
		}
		else
			buffer += 1;
	}

	return token;

}
