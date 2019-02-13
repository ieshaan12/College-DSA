#include<stdio.h>
#include<stdlib.h>
int p(int n)
{int pilani;
printf("%p\t%d\n",&n,n);
p(n+1);
}
int g()
{int goa;
printf("%u\n",&goa);
}
int h()
{int hyd;
printf("%u\n",&hyd);
}
int d()
{int dub;
printf("%u\n",&dub);
}
int main()
{p(0);
//g();
//h();
//d();
}
