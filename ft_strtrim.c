#include "stddef.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t start;
	size_t end;
	char *trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (to_trim(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (to_trim(set, s1[end - 1]))
		end--;
	trimmed = ft_substr(s1, start - 1, end - start - 1);
	if (trimmed == NULL)
		return (NULL);
	return (trimmed);
} 

static int to_trim(const char *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}