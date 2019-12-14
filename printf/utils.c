#include "header.h"

char	*generateNChars(char c, int number)
{
	int i;
	char *str;
	if(number > 0)
		str = ft_calloc(sizeof(char), number + 1);
	else
		return (ft_strdup(""));
	i = 0;
	while(i++ < number)
		str[i - 1] = c;
	return (str);
}

void    applySpaces(char **str, t_flag flag, int size, int left)
{
	char *aux;
    char *cpy;
    
    size = flag.number - size;
    aux = generateNChars(' ', size);
    cpy = *str;
    if(left)
        *str = ft_strjoin(aux, *str);
    else
        *str = ft_strjoin(*str, aux);
    free(cpy);
    free(aux);
}
char	*applyCeros(t_flag flag, char *str)
{
	int size;
	char *ret;

	if(flag.active)
	{
		size = ft_strlen(str);
		size = flag.number - size;
		if(size > 0)
		{
			ret = malloc(sizeof(char) * (flag.number + 1));		
			ft_memset(ret, '0', size);
			ft_strlcpy(&ret[size], str, ft_strlen(str) + 1);
			free(str);
			return (ret);
		}
	}
	return (str);
}

char	*applyCerosHex(t_flag flag, char *str)
{
	int size;
	char *ret;
	char *aux;

	if(flag.active)
	{
		size = ft_strlen(str);
		size = flag.number - size;
		if(size > 0)
		{
			ret = malloc(sizeof(char) * (flag.number + 1));		
			ft_memset(ret, '0', size);
			ret[size] = '\0';
			aux = ret;
			ret = ft_strjoin("0x", ret);
			free(aux);
			aux = ret;
			ret = ft_strjoin(ret, &str[2]);
			free(aux);
			free(str);
			return (ret);
		}
	}
	return (str);
}

char byteToHex(char c)
{
	if(c < 10)
		return (c + '0');
	else if (c < 16)
		return (c +  'a' - 10);
	else
		return (0);
}

void toUpperCase(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		str[i] = ft_toupper((int)str[i]);
		i++;
	}
}