#include <stddef.h>

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t i;
	char *substr;

	if (s == NULL)
		return (NULL);

	i = ft_strlen(s);
	if (start >= i)
		len = 0;

	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);

	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
