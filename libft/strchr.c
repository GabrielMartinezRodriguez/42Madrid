/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:57:05 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/06 13:11:22 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *strchr(const char *s, int c)
{
    char    *devolver;
    int     i;
    int     fin;

    devolver = NULL;
    i = 0;
    fin = 0;
    while(fin == 0)
    {
        if(c == s[i])
        {
            devolver = &s[i];
            fin = 1;
        }
        if(s[i] == '/0')
            fin = 1;
        i++;
    }
    return (devolver);
}