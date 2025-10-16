#include <stddef.h>

char *ft_strrchr(const char *s, int c)
{
	size_t i;
	char *last = NULL;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last);
}