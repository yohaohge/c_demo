#include <stdio.h>
#include <stdlib.h>

char* find_char(char const *source, char const *chars)
{
	if(source == NULL || chars == NULL)
		return NULL;
	char* pSrc = source;
	char* pCh = chars;

	int i = 0;

	while( *(pCh + i) != '\0' )
	{
		if(*(pSrc + i) == '\0')
			return NULL;
		if(*(pCh + i ) == *(pSrc + i))
		{
			i++;
		}
		else
		{
			i = 0;
			pSrc++;
			pCh++;
			pCh = chars;
		}
	}

	return pSrc;
}

int main()
{
	char *src = "Hello， World";
	char *target = "World";
	char *res = 	find_char(src, target);
	printf("%s", res);
}
