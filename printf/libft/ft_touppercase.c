/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touppercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:12:29 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/14 14:13:25 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_touppercase(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		str[i] = ft_toupper((int)str[i]);
		i++;
	}
}