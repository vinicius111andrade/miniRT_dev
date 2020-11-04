#include "test_vectors.h"

int			test_v_crossproduct(double xa, double ya, double za, double xb, double yb, double zb)
{
	int			correct;
	t_vector	crossproduct;
	t_vector	vect_a;
	t_vector	vect_b;
	t_vector	vect_c;

	correct = 1;
	crossproduct = v_define(0, 0, 0);
	crossproduct.x = ya * zb - za * yb;
	crossproduct.y = za * xb - xa * zb;
	crossproduct.z = xa * yb - ya * xb;

	vect_a = v_define(xa, ya, za);
	vect_b = v_define(xb, yb, zb);
	vect_c = v_crossproduct(vect_a, vect_b);
	if (vect_c.x != crossproduct.x)
		correct = 0;
	else if (vect_c.y != crossproduct.y)
		correct = 0;
	else if (vect_c.z != crossproduct.z)
		correct = 0;

	return (correct);
}