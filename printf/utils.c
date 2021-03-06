/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:15:51 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/15 13:41:46 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*generate_chars(char c, int number)
{
	int		i;
	char	*str;

	if (number > 0)
		str = ft_calloc(sizeof(char), number + 1);
	else
		return (ft_strdup(""));
	i = 0;
	while (i++ < number)
		str[i - 1] = c;
	return (str);
}

void	apply_spaces(char **str, t_flag flag, int size, int left)
{
	char *aux;
	char *cpy;

	size = flag.number - size;
	aux = generate_chars(' ', size);
	cpy = *str;
	if (left)
		*str = ft_strjoin(aux, *str);
	else
		*str = ft_strjoin(*str, aux);
	free(cpy);
	free(aux);
}

char	*apply_ceros(t_flag flag, char *str)
{
	int		size;
	char	*ret;

	if (flag.active)
	{
		size = ft_strlen(str);
		size = flag.number - size;
		if (size > 0)
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

char	*apply_ceros_hex(t_flag flag, char *str, int precision)
{
	int		size;
	char	*ret;
	char	*aux;

	if (flag.active)
	{
		if (precision == 1 && flag.number == 0)
			return (ft_strdup("0x"));
		size = ft_strlen(str);
		size = flag.number - size + (precision == 1 ? 2 : 0);
		if (size > 0)
		{
			ret = malloc(sizeof(char) * (flag.number + 1));
			ft_memset(ret, '0', size);
			ret[size] = '\0';
			ret = ft_strjoin("0x", ret);
			aux = ret;
			ret = ft_strjoin(ret, &str[2]);
			free(aux);
			free(str);
			return (ret);
		}
	}
	return (str);
}

char	byte_to_hex(char c)
{
	if (c < 10)
		return (c + '0');
	else if (c < 16)
		return (c + 'a' - 10);
	else
		return (0);
}
