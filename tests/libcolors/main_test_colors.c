
#include "test_colors.h"

int		main(void)
{
	t_colors	clr1;
	t_colors	clr2;
	t_colors	clr3;
	t_colors	clr4;
	t_colors	clr5;
	t_colors	clr6;
	int			out1;
	int			out2;
	int			out3;

	//clrx = colors(alpha/transparency, red, green, blue);
	clr1 = norm_colors(colors(60, 100, 0, 0));
	clr2 = norm_colors(colors(20, 0, 255, 0));
	clr3 = add_colors(clr1, clr2);
	clr4 = sub_colors(clr1, clr3);
	clr5 = scale_colors(2, clr1);
	clr6 = hadamard_product(clr1, clr2);

	printf("\nFirst check if it is creating the structs properly\n");
	printf("Expected: 60, 100, 0, 0\n");
	printf("Output: %f, %f, %f, %f\n", clr1.a, clr1.r, clr1.g, clr1.b);
	printf("Expected: 20, 0, 255, 0\n");
	printf("Output: %f, %f, %f, %f\n", clr2.a, clr2.r, clr2.g, clr2.b);

	printf("\nCheck sum and sub\n");
	printf("Expected: 80, 100, 255, 0\n");
	printf("Output: %f, %f, %f, %f\n", clr3.a, clr3.r, clr3.g, clr3.b);
	printf("Expected: -20, 0, -255, 0\n");
	printf("Output: %f, %f, %f, %f\n", clr4.a, clr4.r, clr4.g, clr4.b);

	printf("\nCheck scaling, multiplying\n");
	printf("Expected: 120, 200, 0, 0\n");
	printf("Output: %f, %f, %f, %f\n", clr5.a, clr5.r, clr5.g, clr5.b);

	clr3 = refit_colors(clr3);
	clr4 = refit_colors(clr4);
	clr5 = refit_colors(clr5);

	printf("\nCheck if it is fit\n");
	printf("Clr3: %f, %f, %f, %f\n", clr3.a, clr3.r, clr3.g, clr3.b);
	printf("Clr4: %f, %f, %f, %f\n", clr4.a, clr4.r, clr4.g, clr4.b);
	printf("Clr5: %f, %f, %f, %f\n", clr5.a, clr5.r, clr5.g, clr5.b);

	out1 = argb_to_int(clr1);
	out2 = argb_to_int(clr2);
	out3 = argb_to_int(clr3);

	printf("\nCheck if int is correct\n");
	printf("Out1: %d\n", out1);
	printf("Out2: %d\n", out2);
	printf("Out3: %d\n", out3);

	printf("\nCheck if Hadamard Product works\n");
	printf("Expected: 0,01845444, 0, 0, 0\n");
	printf("Clr6: %f, %f, %f, %f\n", clr6.a, clr6.r, clr6.g, clr6.b);

	return (0);
}