/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:50:19 by gmartine          #+#    #+#             */
/*   Updated: 2019/09/11 20:04:09 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_atoi(char *str)
{
    int number;
    int i;
    int sign;

    number = 0;
    i = 0;
    sign = 1;
    while(str[i] == ' ')
        i++;
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        number = 10 * number + str[i] - '0';
        i++;
    }
    return (number);
}