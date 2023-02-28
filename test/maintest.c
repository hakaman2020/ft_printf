#include <stdio.h>
#include "ft_printf.h"

/*
**
**This function is to test all kinds of edge cases of the printf function
** the mandatory conversions are "cspdiuxX%" Bonus "n g f e"
** the mandatory flags "-0.*" Bonus " hh h ll l"
*/

int main()
{
	//char *s = "hello";
	//unsigned int d = NULL;
	//unsigned int d = 4294967295;
	int d = -12;
	printf(" outcome:%d\n",ft_printf("ftint:%*d|",4,d));
	printf(" outcome:%d\n",   printf("print:%*d|",4,d));
	//printf(" outcome:%d\n",ft_printf("ftint:%10d|",d));
	//printf(" outcome:%d\n",   printf("print:%10d|",d));
	//printf(" outcome:%d\n",ft_printf("ftint:%.5d|",d));
	//printf(" outcome:%d\n",   printf("print:%.5d|",d));
	//printf(" outcome:%d\n",ft_printf("ftint:%20.12d|",d));
	//printf(" outcome:%d\n",   printf("print:%20.12d|",d));
	//printf(" outcome:%d\n",ft_printf("ftint:%10.5d|",d));
	//printf(" outcome:%d\n",   printf("print:%10.5d|",d));
	//printf(" outcome:%d\n",ft_printf("ftint:%-10.5d|",d));
	//printf(" outcome:%d\n",   printf("print:%-10.5d|",d));
	//printf(" outcome:%d\n",ft_printf("ftint:%-10.d|",d));
	//printf(" outcome:%d\n",   printf("print:%-10.d|",d));
	//printf(" outcome:%d\n",ft_printf("ftint:%10.d|",d));
	//printf(" outcome:%d\n",   printf("print:%10.d|",d));
	//printf(" outcome:%d\n",ft_printf("ftint:%-10d|",NULL));
	//printf(" outcome:%d\n",   printf("print:%-10d|",NULL));
	return (0);
}
