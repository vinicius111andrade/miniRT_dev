#include "test_vectors.h"

int			test_v_scale(double x, double y, double z, double scalar)
{
	int			correct;
	t_vector	vector;
	t_vector	sca_vec;

	correct = 0;
	vector = v_define(x, y, z);
	sca_vec = v_define(x, y, z);
	sca_vec.x = scalar * vector.x;
	sca_vec.y = scalar * vector.y;
	sca_vec.z = scalar * vector.z;
	vector = v_scale(scalar, vector);

	if (sca_vec.x == vector.x)
		correct++;
	if (sca_vec.y == vector.y)
		correct++;
	if (sca_vec.z == vector.z)
		correct++;

	return (correct);
}