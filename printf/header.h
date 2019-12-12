/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:30:15 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/12 20:57:47 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "unistd.h"
# include "libft/libft.h"

typedef struct s_flag{
	int active;
	int number;
}               t_flag;

typedef struct s_list_flags
{
	t_flag	minimum;
	t_flag	sign;
	t_flag	cero;
	t_flag	precision;
}               t_list_flags;

int		ft_printf(const char *str, ...);
int		ft_isConversion(int c);
int		ft_readNumber(const char *str, va_list ap);
int		ft_ScanFlag(t_flag *flag, char *str, int *i, va_list ap);
int		printVariable(char *str, va_list ap, char **buff);

char     *printIntegers(t_list_flags flags, va_list ap);
char     *strCeros(t_flag flag, char *str);

char		*printString(t_list_flags flags, va_list ap);
//UTILS
char     *generateNChars(char c, int number);
void 		applySpaces(char **str, t_flag flags, int size, int left);
#endif