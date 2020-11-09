#ifndef TESTS_VECTORS_H
# define TESTS_VECTORS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../my_libs/vectors/libvectors.h"

int		test_v_define(double x,double y,double z);
int		test_v_invert_direction(double x, double y, double z);
int		test_v_add(double xa, double ya, double za, double xb, double yb, double zb);
int		test_v_subtract(double xa, double ya, double za, double xb, double yb, double zb);
int		test_v_dotproduct(double xa, double ya, double za, double xb, double yb, double zb);
int		test_v_crossproduct(double xa, double ya, double za, double xb, double yb, double zb);
int		test_v_length(double x, double y, double z);
int		test_v_normalize(double x, double y, double z);
int		test_v_cos(double xa, double ya, double za, double xb, double yb, double zb);
int		test_v_sin(double xa, double ya, double za, double xb, double yb, double zb);
int		test_v_scale(double x, double y, double z, double scalar);

#endif