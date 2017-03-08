#include <stdio.h>
#include <math.h>
int main()
{ 
    char x = 'm';
    printf("%c\n", x);
    {
        printf("%c\n", x);
        char x = 'b';
        printf("%c\n", x);
    }
    printf("%c\n", x);


	int i=1;
	printf("%i\n",i++);
	printf("%i\n",++i);

	i=1;
	printf("%i %i\n",i++,++i);

	return 0;
}
