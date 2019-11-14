/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:12:15 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/14 18:00:16 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	int				ret;

	if (src == NULL)
		return (0);
	if (dest == NULL)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	ret = i;
	i = 0;
	while (i < size - 1 && src[i] != '\0' && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ret);
}
