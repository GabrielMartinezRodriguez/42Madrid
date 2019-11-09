/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:44:27 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/09 20:02:21 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>

int				ft_atoi(char *str);
void			ft_bzero(void *mem, size_t len);
void			*ft_calloc(size_t n, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *destination, const void *source, int c, size_t num);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void			*ft_memcpy(void *destination, const void *source, size_t num);
void			*ft_memmove(void *destination, const void *source, size_t num);
void			*ft_memset(void *mem, int byte, size_t len);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(const char *str1);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strlen(const char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(char *str, char *to_find, size_t len);
char			*ft_strrchr(char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char            *ft_strjoin(char const *s1, char const *s2);
char            *ft_substr(char const *s, unsigned int start, size_t len);
char            *ft_strtrim(char const *s1, char const *set);
char            *ft_strndup(const char *str1, int n);
char            **ft_insert_string(char **table, char *str);
char            *ft_itoa(int n);
char            **ft_split(char const *s, char c);
char            *ft_strndup(const char *str1, int n);
char			**ft_insert_string(char **table, char *str);
#endif
