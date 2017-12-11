#include <stdio.h>  

int main()
{
	int a[] = {0, 1, 2, 3, 4 ,5, 6, 7};
	int i, j, k;
	int n = 1 << 8;
	for (i = 0; i < n; i++)
	{
		j = i;
		k = 0;
		printf("{");
		while (j)
		{
			if (j & 1)
			{
				printf("%d", a[k]);
			}
			j >>= 1;
			++k;
		}
		printf("}\n");
	}

	return 0;
}