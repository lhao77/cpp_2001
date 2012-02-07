#include <stdio.h>

class base
{
public:
       void f(){printf("base::f()");}
};

class der : public base
{
public:
       void f(){printf("der::f()");}      
};

int main()
{
    der *d = new der;
    d->f();
    
    printf("\ninput 'q' to quit.");
    char c;
    scanf("%d",c);
}
