#include <stdio.h>

void	test_minirt()
{
	printf("\nSTART of minirt.c tests\n\n");

	if (minirt() == 0)
		printf("Return correto.\n");
	else
		printf("Return errado.\n");
	
	printf("\nEND of minirt.c tests\n\n");

}