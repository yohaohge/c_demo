#include <stdlib.h>
#include <stdio.h>

int string_length(const char *string)
{
	if(string == NULL) return 0;
	char *p = string;
	while(*p != '\0') p++;
	return (int)(p - string);	
}
void reverse_string(char *string)
{
	if(string == NULL||*string == '\0') return;

	char *p = string;
	char *end = string + string_length(string) - 1;

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

	char str[] = "HELLO WORLD";
	printf("len = %d", string_length(str));
	reverse_string(str);
	printf("%s\n", str);
	return 0;		
}
