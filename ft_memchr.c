#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)	
{
	size_t i;
	unsigned char *ptr;
	unsigned char ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ch)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}