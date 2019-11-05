/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:50:19 by gmartine          #+#    #+#             */
/*   Updated: 2019/09/11 20:04:09 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int	flag;
	int	i;

	flag = 1;
	i = 0;
	if (str[0] == '\0')
		return (flag);
	while (str[i] != '\0')
	{
		if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
		{
			flag = 0;
			return (flag);
		}
		else
			i++;
	}
	return (flag);
}
