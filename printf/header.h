/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:30:15 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/15 12:32:34 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "unistd.h"
# include "libft/libft.h"

typedef struct	s_flag{
	int active;
	int number;
	int star;
}				t_flag;

typedef struct	s_list_flags
{
	t_flag	minimum;
	t_flag	sign;
	t_flag	cero;
	t_flag	precision;
}				t_list_flags;

int				ft_printf(const char *str, ...);
int				show_str(char *buff, unsigned int len);

int				ft_is_conversion(int c);
int				ft_read_number(const char *str, va_list ap);
void			ft_scan_flag(t_flag *flag, char *str, int *i, va_list ap);
int				print_variable(char *str, va_list ap, char **buff);
char			*render_variable(char c, t_list_flags flags, va_list ap);

char			*print_integers(t_list_flags flags, va_list ap);
char			*str_ceros(t_flag flag, char *str);
char			*str_precision(t_flag flag, char *str);

char			*print_string(t_list_flags flags, va_list ap);
char			*string_precision(char *string, int number);

char			*print_char(t_list_flags flags, va_list ap);
char			*char_to_string(char c);
int				null_case(int get, int set);

char			*print_per_cent(t_list_flags flags);

char			*print_pointer(t_list_flags flags, va_list ap);
char			*ptr_to_str(void *ptr);
char			byte_to_hex(char c);
char			*ini_str_ptr();

char			*print_unsigned_integers(t_list_flags flags, va_list ap);

char			*print_unsigned_hex(t_list_flags flags, va_list ap);
char			*unsigned_to_hex(unsigned int number);

char			*generate_chars(char c, int number);
void			apply_spaces(char **str, t_flag flags, int size, int left);
char			*apply_ceros(t_flag flag, char *str);
char			*apply_ceros_hex(t_flag flag, char *str, int precision);

void			star_exceptions(t_list_flags *flags);
#endif
