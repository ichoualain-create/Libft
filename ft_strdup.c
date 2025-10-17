#include "libft.h"

void *ft_strdup(const char *s1)
{
	size_t i;
	char *dup;

	i = 0;
	dup = malloc(ft_strlen(s1) + 1);
	if (dup == NULL)
		return (NULL);

	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
