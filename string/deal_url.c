#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STR_LEN 256
char host[MAX_STR_LEN] = {0};
int  port = 80;

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: %s URL\n", argv[0]);
		return 1;
	}

	// get host
	int iIndex =0;
	char *pLocal = NULL;

	if( (pLocal = strstr(argv[1], "://")) == NULL )
	{
		printf("%s is not a valid url\n", argv[1]);
		return 1;
	}	
	pLocal = pLocal + 3;

	char *pLocalEnd = NULL;
	if((pLocalEnd = strchr(pLocal, '/')) == NULL )
	{
		printf("%s is not a valid url\n", argv[1]);
		return 1;
	}	
	
	int iLen = pLocalEnd - pLocal;
	strncpy(host, pLocal, iLen);
	
	printf("Host: %s \n", host);
	// get port
	pLocal = NULL;
	if( (pLocal = strchr(host, ':')) != NULL)
	{
		pLocal = pLocal+1;
		port = atoi(pLocal);
	}
	printf("Port: %d\n", port);
	// get param
	pLocalEnd = pLocalEnd + 1;
	char strName[MAX_STR_LEN] = {0};
	char strValue[MAX_STR_LEN] = {0};

	pLocal = NULL;
	if( (pLocalEnd = strchr(pLocalEnd, '?')) == NULL )
	{
		return 0;
	}
	pLocalEnd = pLocalEnd + 1;

	while( (pLocal = strchr(pLocalEnd, '=')) != NULL)
	{
		memset(strName, 0, sizeof(strName));
		memset(strValue, 0, sizeof(strValue));
		// get param name
		iLen = pLocal - pLocalEnd;
		strncpy(strName, pLocalEnd, iLen);
		pLocalEnd = pLocal + 1;
		// get param value
		if( (pLocal = strchr(pLocalEnd, '&')) != NULL )
		{
			
			iLen = pLocal - pLocalEnd; 
			strncpy(strValue, pLocalEnd, iLen);
		}
		else
		{
			strcpy(strValue, pLocalEnd );
		}

		printf("Param name: %s value: %s\n", strName, strValue);
		if(pLocal)
			pLocalEnd = pLocal + 1;
		else
			break;

	}
	return 0;
}
