/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:11:48 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/14 18:17:40 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*devolver;
	int		i;
	int		fin;

	devolver = NULL;
	i = 0;
	fin = 0;
	while (fin == 0)
	{
		if (c == s[i])
			devolver = (char *)(&s[i]);
		if (s[i] == '\0')
			fin = 1;
		i++;
	}
	return (devolver);
}
