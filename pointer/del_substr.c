#include <stdio.h>
#include <stdlib.h>

int del_substr(char  *str, char const *substr)
{
	if(str == NULL || substr == NULL)
		return 0;
	char* pSrc = str;
	char* pCh = substr;

	int i = 0;

	while( *(pCh + i) != '\0' )
	{
		if(*(pSrc + i) == '\0')
			return 0;
		if(*(pCh + i ) == *(pSrc + i))
		{
			i++;
		}
		else
		{
			i = 0;
			pSrc++;
			pCh++;
			pCh = substr;
		}
	}

	pCh = pSrc + i;
	while( *pCh != '\0')
	{
		*pSrc++ = *pCh++;
	}
	*pSrc = '\0';


	return 0;
}

int main()
{
	char src[1024] = "Hello， World";
	char *target = "World";
	int res = del_substr(src, target);
	printf("%s %d",src, res);
}
