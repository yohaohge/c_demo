#include <stdlib.h>
#include <stdio.h>

void reverse_string(char *string)
{
	if(string == NULL||*string == '\0') return;

	char *p = string;
	char *end = string;
	while(*end != '\0') end++;
	end--;

	while(p < end)
	{
		char tmp = *end;
		*end = *p;
		*p = tmp;
		p++; end--;
	}
	
}
int main()
{

	char str[1024] = "Hello,World";
	reverse_string(str);
	printf("%s\n", str);
	return 0;		
}
