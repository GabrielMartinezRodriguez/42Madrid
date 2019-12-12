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