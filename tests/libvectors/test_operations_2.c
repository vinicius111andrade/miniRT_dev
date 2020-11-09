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

int			test_v_distance(double x, double y, double z)
{
	int			correct;
	t_vector	v2;
	t_vector	v1;
	double		d;

	correct = 0;
	v1 = v_define(0, 0, 0);
	v2 = v_define(x, y, z);
	d = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));

	if (d == v_distance(v1, v2))
		correct++;

	return (correct);
}

void		test_x_axis_rotation()
{
	t_vector	vector;
	t_vector	rot_vector;
	t_vector	out_vector;
	double		deg_angle;

	deg_angle = 180;
	vector = v_define(1, 1, 1);
	rot_vector = v_define(1, -1, -1);
	out_vector = x_axis_rotation(vector, deg_angle);
	printf("\ntest_x_axis_rotation\n");
	printf("Expected: %f, %f, %f\n", rot_vector.x, rot_vector.y, rot_vector.z);
	printf("Output: %f, %f, %f\n\n", out_vector.x, out_vector.y, out_vector.z);

	return ;
}

void		test_y_axis_rotation()
{
	t_vector	vector;
	t_vector	rot_vector;
	t_vector	out_vector;
	double		deg_angle;

	deg_angle = 180;
	vector = v_define(1, 1, 1);
	rot_vector = v_define(-1, 1, -1);
	out_vector = y_axis_rotation(vector, deg_angle);
	printf("\ntest_y_axis_rotation\n");
	printf("Expected: %f, %f, %f\n", rot_vector.x, rot_vector.y, rot_vector.z);
	printf("Output: %f, %f, %f\n\n", out_vector.x, out_vector.y, out_vector.z);

	return ;
}

void		test_z_axis_rotation()
{
	t_vector	vector;
	t_vector	rot_vector;
	t_vector	out_vector;
	double		deg_angle;

	deg_angle = 180;
	vector = v_define(1, 1, 1);
	rot_vector = v_define(-1, -1, 1);
	out_vector = z_axis_rotation(vector, deg_angle);
	printf("\ntest_z_axis_rotation\n");
	printf("Expected: %f, %f, %f\n", rot_vector.x, rot_vector.y, rot_vector.z);
	printf("Output: %f, %f, %f\n\n", out_vector.x, out_vector.y, out_vector.z);

	return ;
}