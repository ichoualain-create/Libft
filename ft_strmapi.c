#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	char *mapped;

	if (s == NULL || f == NULL)
		return (NULL);
	mapped = malloc(ft_strlen(s) + 1);
	if (mapped == NULL)
		return (NULL);

	i = 0;
	while (s[i])
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}