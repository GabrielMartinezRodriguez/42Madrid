/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:59:59 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/09 19:37:05 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char **ft_insert_string(char **table, char *str)
{
    int i;
    char **aux;

    while(table != NULL)
        i++;
    i++;
    aux = malloc(i * sizeof(char *));
    i = 0;
    while(table != NULL)
    {
        aux[i]=table[i];
        i++;
    }
    aux[i] = str;
    aux[i + 1] = NULL;
    free(table);
    return aux;
}
