#include "test_vectors.h"

int			test_v_crossproduct(double xa, double ya, double za, double xb, double yb, double zb)
{
	int			correct;
	t_vector	crossproduct;
	t_vector	vect_a;
	t_vector	vect_b;
	t_vector	vect_c;

	correct = 0;
	crossproduct = v_define(0, 0, 0);
	crossproduct.x = ya * zb - za * yb;
	crossproduct.y = za * xb - xa * zb;
	crossproduct.z = xa * yb - ya * xb;

	vect_a = v_define(xa, ya, za);
	vect_b = v_define(xb, yb, zb);
	vect_c = v_crossproduct(vect_a, vect_b);
	if (vect_c.x == crossproduct.x)
		correct++;
	if (vect_c.y == crossproduct.y)
		correct++;
	if (vect_c.z == crossproduct.z)
		correct++;

	return (correct);
}

int			test_v_length(double x, double y, double z)
{
	int			correct;
	t_vector	vector;
	double		length;

	correct = 0;
	vector = v_define(x, y, z);
	length = sqrt(v_dotproduct(vector, vector));
	if (length == v_length(vector))
		correct++;

	return (correct);
}

int			test_v_normalize(double x, double y, double z)
{
	int			correct;
	t_vector	vector;
	double		norm;
	t_vector	unit_vec;

	correct = 0;
	vector = v_define(x, y, z);
	norm = v_length(vector);
	unit_vec.x = vector.x / norm;
	unit_vec.y = vector.y / norm;
	unit_vec.z = vector.z / norm;
	vector = v_normalize(vector);

	if (unit_vec.x == vector.x)
		correct++;
	if (unit_vec.y == vector.y)
		correct++;
	if (unit_vec.z == vector.z)
		correct++;

	return (correct);
}

int			test_v_cos(double xa, double ya, double za, double xb, double yb, double zb)
{
	int			correct;
	t_vector	vect_a;
	t_vector	vect_b;
	double		cos;

	correct = 0;
	vect_a = v_define(xa, ya, za);
	vect_b = v_define(xb, yb, zb);
	cos = v_dotproduct(vect_a, vect_b) / (v_length(vect_a) * v_length(vect_b));
	if (cos == v_cos(vect_a, vect_b))
		correct++;

	return (correct);
}

int			test_v_sin(double xa, double ya, double za, double xb, double yb, double zb)
{
	int			correct;
	t_vector	vect_a;
	t_vector	vect_b;
	double		sin;

	correct = 0;
	vect_a = v_define(xa, ya, za);
	vect_b = v_define(xb, yb, zb);
	sin = sqrt(1 - pow(v_cos(vect_a, vect_b), 2));
	if (sin == v_sin(vect_a, vect_b))
		correct++;

	return (correct);
}