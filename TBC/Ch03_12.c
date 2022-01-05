#include <stdio.h>
#include <float.h>


int main()
{
	// round-off errors (ex1)
	
	/*float a, b;
	a = 1.0E20f + 1.0f;
	b = a - 1.0E20f;
	printf("%f\n", b);*/

	// round-off errors (ex2)

	//float a = 0.0f;

	/*a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;
	a = a + 0.01f;

	printf("%f\n", a); */ 
		// 0.99999 not 1

	// overflow

	/*float max = 3.402823466e+38F;
	printf("%f\n", max);
	max = max * 100.0f;
	printf("%f\n", max);*/

	// underflow

	float f = 1.401298464e-45F;
	printf("%e\n", f);
	f = f / 100.0f; //subnormal
	printf("%e\n", f);

	return 0;
}