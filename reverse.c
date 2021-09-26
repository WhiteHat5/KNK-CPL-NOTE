#include <stdio.h>

int main(int argc, char* argv[])
{
	int n = argc - 1;
	
	while(n > 0)
		printf("%s ", argv[n--]);
	putchar('\n');
	return 0;

}
