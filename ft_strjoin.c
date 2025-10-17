#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t i;
	size_t j;
	char *joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined == NULL)
		return (NULL);

	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}