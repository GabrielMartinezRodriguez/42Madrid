/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:44:27 by gmartine          #+#    #+#             */
/*   Updated: 2019/11/11 23:44:40 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

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
char            *ft_strmapi(char *s, char (*f)(unsigned int, char));
void            ft_putstr_fd(char *s, int fd);
void            ft_putchar_fd(char c, int fd);
void	        ft_putnbr(int nb);
void            ft_putnbr_fd(int nb, int fd);
void            ft_putendl_fd(char *s, int fd);
t_list			*ft_lstnew(void const *content);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
#endif
