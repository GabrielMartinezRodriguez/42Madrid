/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:36:03 by gmartine          #+#    #+#             */
/*   Updated: 2019/09/12 19:57:27 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int					i;
	int					flag;
	int					first;
	unsigned char		*u_s1;
	unsigned char		*u_s2;

	i = 0;
	flag = 0;
	first = 1;
	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while (((u_s1[i] != '\0' && flag == 0) || first == 1) && i < n)
	{
		if (u_s1[i] < u_s2[i])
			flag = -1;
		else if (u_s1[i] > u_s2[i])
			flag = 1;
		i++;
		first = 0;
	}
	return (flag);
}
