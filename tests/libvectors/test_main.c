#include "test_vectors.h"

int		main()
{
	int		correct;

	correct = 0;

	printf("\nTesting lib vectors!\n");
	if (test_v_define(0, 0, 0))
		correct++;
	else
		printf("\nERRO v_define\n");

	if (test_v_invert_direction(-52, 45, 0.1112))
		correct++;
	else
		printf("\nERRO v_invert_direction\n");

	if (test_v_add(-0.2345, 5, -200, 5, 0, -2.2))
		correct++;
	else
		printf("\nERRO v_add\n");

	if (test_v_subtract(-0.2345, 5, -200, 5, 0, -2.2))
		correct++;
	else
		printf("\nERRO v_subtract\n");

	if (test_v_dotproduct(-0.2345, 5, -200, 5, 0, -2.2))
		correct++;
	else
		printf("\nERRO v_dotproduct\n");

	if (test_v_crossproduct(-0.2345, 5, -200, 5, 0, -2.2))
		correct++;
	else
		printf("\nERRO v_crossproduct\n");

	printf("\nNumber of correct functions: %d out of 14\n", correct);
}