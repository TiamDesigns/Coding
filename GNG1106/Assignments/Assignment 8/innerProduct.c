#include <stdio.h>
#define TRUE 1
#define FALSE 0


// the structure representing a vector
typedef struct
{
	int length; // length of the vector
	double *ptr; // the pointer pointing to the first element of the vector
}VECTOR;

// the function returns the inner product of two vectors
double innerProduct(VECTOR *A, VECTOR *B, int *ptrError)
{
	double result=0;
	int i;
	
	if (A->length != B->length)
	{
		*ptrError = TRUE;
		printf("\t\t the lengths of input vectors do not match!\n");
	}
	else
	{
		// TO DO
	}
	return result;
}

int main()
{
	double a[3]={0.3, 0.4, 0.5};
	double b[3]={1, 1, 1};
	double c[4]={0.2, 0.3, 0.4, 0.5};
	double d[4]={0.5, 1, 0.5, 1};
	VECTOR u, v, w, x;
	int error;
	double answer;

	u.length=3;
	u.ptr=a;
	v.length=3;
	v.ptr=b;
	w.length=4;
	w.ptr=c;
	x.length=4;
	x.ptr=d;

	error=FALSE;
	answer=innerProduct(&u, &v, &error);
	if (!error)
		printf("inner product of u and v is %f\n", answer);

        error=FALSE;
        answer=innerProduct(&w, &x, &error);
        if (!error)
                printf("inner product of w and x is %f\n", answer);

        error=FALSE;
        answer=innerProduct(&u, &x, &error);
        if (!error)
                printf("inner product of u and x is %f\n", answer);

	return 0;
}

