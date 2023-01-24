#include "minimath.h"
int main(void)
{
	t_vec3 a, b, c, d;

	input_vec3(a, 10.0, -21.0, 42.0);

	printf("\nvector a : ");
	print_vec3(a);

	add_vec3(b, a, a);
	printf("\nvector b : ");
	print_vec3(b);

	sub_vec3(c, a, b);
	printf("\nvector c : ");
	print_vec3(c);
	
	printf("\ndot_product(a,c) = %f", dot_product(a,c));
	cross_product(d, a, c);	
	printf("\ncross_product(a,c) = %f", d);


	printf("\nsqrsum of a : %f\n", sqrsum_vec3(a));
	printf("\nlen of a : %f\n", length_vec3(a));
	normalize_vec3(a, a);
	print_vec3(a);
	printf("\nsqrsum of a : %f\n", sqrsum_vec3(a));
	printf("\nlen of a : %f\n", length_vec3(a));

	t_mtx3 mtx;
	input_mtx3(mtx, a, b, c);
	print_mtx3(mtx);
	double det = det_mtx3(mtx);
	printf("det(mtx) : %f \n", det);

	t_vec3	v1, v2, v3;
	input_vec3(v1, 1, 2, 3);
	input_vec3(v2, 1, 0, 3);
	input_vec3(v3, 0, 2, 3);

	t_mtx3	mtx_, mtx0, inv;
	input_mtx3(mtx0, v1, v2, v3);
	inverse_mtx3(inv, mtx0);
	print_mtx3(inv);

	mul_mtx3(mtx_, inv, mtx0);
	print_mtx3(mtx_);
	mul_mtx3(mtx_, mtx0, inv);
	print_mtx3(mtx_);

	printf("\nend of program!\n");
	return (0);
}

