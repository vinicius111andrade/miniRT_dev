#include "test_vectors.h"

int		test_v_define(double x,double y,double z)
{
	t_vector	vector;
	int			correct;

	correct = 0;
	vector = v_define(x, y, z);
	if (vector.x == x && vector.y == y && vector.z == z)
		correct++;
	if (sizeof(x) == sizeof(double))
		correct++;
	if (sizeof(y) == sizeof(double))
		correct++;
	if (sizeof(z) == sizeof(double))
		correct++;
	return(correct);
}

int		test_v_invert_direction(double x, double y, double z)
{
	t_vector	vector;
	t_vector	inv_vect;
	t_vector	inv_inv_vect;
	int			correct;

	correct = 0;
	vector = v_define(x, y, z);
	inv_vect = v_invert_direction(vector);
	inv_inv_vect = v_invert_direction(inv_vect);
	if (vector.x == -inv_vect.x)
		correct++;
	if (vector.y == -inv_vect.y)
		correct++;
	if (vector.z == -inv_vect.z)
		correct++;
	if (vector.x == inv_inv_vect.x)
		correct++;
	if (vector.y == inv_inv_vect.y)
		correct++;
	if (vector.z == inv_inv_vect.z)
		correct++;

	return correct;
}

int		test_v_add(double xa, double ya, double za, double xb, double yb, double zb)
{
	int			correct;
	t_vector	vect_a;
	t_vector	vect_b;
	t_vector	vect_sum;
	double		x_sum;
	double		y_sum;
	double		z_sum;

	correct = 0;
	vect_a = v_define(xa, ya, za);
	vect_b = v_define(xb, yb, zb);
	vect_sum = v_add(vect_a, vect_b);
	x_sum = xa + xb;
	y_sum = ya + yb;
	z_sum = za + zb;

	if (vect_sum.x == x_sum)
		correct++;
	if (vect_sum.y == y_sum)
		correct++;
	if (vect_sum.z == z_sum)
		correct++;

	return(correct);
}

int		test_v_subtract(double xa, double ya, double za, double xb, double yb, double zb)
{
	int			correct;
	t_vector	vect_a;
	t_vector	vect_b;
	t_vector	vect_sub;
	double		x_sub;
	double		y_sub;
	double		z_sub;

	correct = 0;
	vect_a = v_define(xa, ya, za);
	vect_b = v_define(xb, yb, zb);
	vect_sub = v_subtract(vect_a, vect_b);
	x_sub = xa - xb;
	y_sub = ya - yb;
	z_sub = za - zb;

	if (vect_sub.x == x_sub)
		correct++;
	if (vect_sub.y == y_sub)
		correct++;
	if (vect_sub.z == z_sub)
		correct++;

	return(correct);
}

int			test_v_dotproduct(double xa, double ya, double za, double xb, double yb, double zb)
{
	int			correct;
	double		dotproduct;
	t_vector	vect_a;
	t_vector	vect_b;

	correct = 0;
	dotproduct = xa * xb + ya * yb + za * zb;
	vect_a = v_define(xa, ya, za);
	vect_b = v_define(xb, yb, zb);
	if (v_dotproduct(vect_a, vect_b) == dotproduct)
		correct++;

	return (correct);
}