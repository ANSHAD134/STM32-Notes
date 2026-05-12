#include <stdio.h>

struct complex
{
    int real;
    int imag;
};

struct complex addcomplex(struct complex c1, struct complex c2)
{
    struct complex sum;
    
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    
    return sum;
}

void Displaycomplex(struct complex c)
{
    printf("%d + %di\n", c.real, c.imag);
}

int main()
{
    struct complex c1, c2, result;
    
    printf("Enter First complex number:");
    scanf("%d %d", &c1.real, &c1.imag);
    
    printf("Enter second complex number:");
    scanf("%d %d", &c2.real, &c2.imag);
    
    result = addcomplex(c1, c2);
    
    printf("Sum = ");
    
    Displaycomplex(result);
    
    return 0;
}