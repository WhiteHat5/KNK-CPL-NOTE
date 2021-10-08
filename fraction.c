#include <stdio.h>

struct fraction {
	int numerator;
	int denominator;
};

struct fraction reduce_to_lowest (struct fraction f);
struct fraction add (struct fraction f1, struct fraction f2);
struct fraction subtract (struct fraction f1, struct fraction f2);
struct fraction multiply (struct fraction f1, struct fraction f2);
struct fraction divide (struct fraction f1, struct fraction f2);
void print_fraction (struct fraction f);


int main(void)
{
	struct fraction samp[] = {{5,8}, {2,3},{4,7},{6,10}};
	
	print_fraction(add(samp[0],samp[3]));
	print_fraction(subtract(samp[2],samp[3]));
	print_fraction(multiply(samp[0],samp[2]));
	print_fraction(divide(samp[0],samp[1]));
	return 0;
}

struct fraction reduce_to_lowest (struct fraction f)
{
	int num = f.numerator, denom = f.denominator;
	int r;
	
	while (denom != 0){
		r = num % denom;
		num = denom;
		denom = r;
	}
	
	return (struct fraction) {f.numerator/num , f.denominator/num};
}

struct fraction add (struct fraction f1, struct fraction f2)
{
	struct fraction res;
	
	res.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	res.denominator = f1.denominator * f2.denominator;
	
	return reduce_to_lowest(res);
}
struct fraction subtract (struct fraction f1, struct fraction f2)
{
	struct fraction res;
	
	res.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
	res.denominator = f1.denominator * f2.denominator;
	
	return reduce_to_lowest(res);
}
struct fraction multiply (struct fraction f1, struct fraction f2)
{
	struct fraction res;
	
	res.numerator = f1.numerator * f2.numerator;
	res.denominator = f1.denominator * f2.denominator;
	
	return reduce_to_lowest(res);
}
struct fraction divide (struct fraction f1, struct fraction f2)
{
	struct fraction res;
	
	res.numerator = f1.numerator * f2.denominator;
	res.denominator = f1.denominator * f2.numerator;
	
	return reduce_to_lowest(res);
}


void print_fraction (struct fraction f)
{
	printf("%d/%d\n", f.numerator, f.denominator);
	return;
}
