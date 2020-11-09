#include "test_vectors.h"

int		main()
{
	int		correct;

	correct = 0;

	printf("\nTesting lib vectors!\n");
	if (test_v_define(0, 0, 0) == 4)
		correct++;
	else
		printf("\nERRO v_define\n");

	if (test_v_invert_direction(-52, 45, 0.1112) == 6)
		correct++;
	else
		printf("\nERRO v_invert_direction\n");

	if (test_v_add(-0.2345, 5, -200, 5, 0, -2.2) == 3)
		correct++;
	else
		printf("\nERRO v_add\n");

	if (test_v_subtract(-0.2345, 5, -200, 5, 0, -2.2) == 3)
		correct++;
	else
		printf("\nERRO v_subtract\n");

	if (test_v_dotproduct(-0.2345, 5, -200, 5, 0, -2.2) == 1)
		correct++;
	else
		printf("\nERRO v_dotproduct\n");

	if (test_v_crossproduct(-0.2345, 5, -200, 5, 0, -2.2) == 3)
		correct++;
	else
		printf("\nERRO v_crossproduct\n");

	if (test_v_length(1,2,3) == 1)
		correct++;
	else
		printf("\nERRO v_length\n");

	if (test_v_normalize(1,2,3) == 3)
		correct++;
	else
		printf("\nERRO v_normalize\n");

	if (test_v_cos(-0.2345, 5, -200, 5, 0, -2.2) == 1)
		correct++;
	else
		printf("\nERRO v_cos\n");

	if (test_v_sin(-0.2345, 5, -200, 5, 0, -2.2) == 1)
		correct++;
	else
		printf("\nERRO v_sin\n");

	if (test_v_scale(0, 3, 4, -5) == 3)
		correct++;
	else
		printf("\nERRO v_scale\n");

	if (test_v_distance(0, 3, 4) == 1)
		correct++;
	else
		printf("\nERRO v_distance\n");

	printf("\nNumber of correct functions: %d out of 12\n", correct);

	test_x_axis_rotation();
	test_y_axis_rotation();
	test_z_axis_rotation();
}