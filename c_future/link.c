#include <stdlib.h>
#include <stdio.h>


extern int func();

int main()
{
	extern int b;
	printf("extern b = %d\n", b);

	func();
	return 0;
}
