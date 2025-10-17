#include "libft.h"

static int ft_len(int n)
{
	size_t count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char *ft_itoa(int n)
{
	char *ptr;
	int len;

	len = ft_len(n);
	ptr = malloc(len + 1);
	if (NULL == ptr)
		return (NULL);
	ptr[len] = '\0';
	if (0 == n)
		ptr[0] = '0';
	else if (n < 0)
		ptr[0] = '-';
		n = -n;
	while (n != 0)
	{
		ptr[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (ptr);
}
