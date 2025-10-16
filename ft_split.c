#include <stddef.h>

int safe_malloc(char **token_v, int position, size_t buffer)
{
	int i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (NULL == token_v[position])
	{
		while (i < position)
			free(token_v[i++]);
		free(token_v);
		return (1);
	}
	return (0);
}

// return 0 if all mallocs went fine, otherwise 1
int fill(char **token_v, char const *s, char delimeter)
{
	size_t len;
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == delimeter && s[i])
			++i;
		while (s[i] != delimeter && s[i])
		{
			++len;
			++i;
		}
		if (len > 0)
		{
			if (safe_malloc(token_v, j, len + 1))
				return (1);
			token_v[j] = ft_substr(s, i - len, len);
		}
		++j;
	}
	return (0);
}

size_t count_tokens(char const *s, char delimeter)
{
	size_t tokens;
	int i;

	i = 0;
	tokens = 0;
	while (s[i])
	{
		while (s[i] == delimeter && s[i])
			i++;
		if (s[i] != delimeter && s[i])
		{
			tokens++;
			while (s[i] != delimeter && s[i])
				i++;
		}
	}
	return (tokens);
}

char **ft_split(char const *s, char c)
{
	size_t tokens;
	char **token_v;

	if (NULL == s)
		return (NULL);
	tokens = 0;
	tokens = count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (NULL == token_v)
		return (NULL);
	token_v[tokens] = NULL;
	if (fill(token_v, s, c))
		return (NULL);
	return (token_v);
}