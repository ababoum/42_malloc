/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:42:42 by mababou           #+#    #+#             */
/*   Updated: 2022/04/13 20:21:10 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// minitests
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
// malloc
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
// mem
void	*ft_memset(void *ptr, int val, size_t count);
void	ft_bzero(void *ptr, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memchr(const void *block, int c, size_t size);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
// numbers
int		ft_atoi(const char *str);
// str_edit
int		ft_toupper(int c);
int		ft_tolower(int c);
// strings
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
// strings_handle
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *substr, size_t len);
// str
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
// strjoin
char	*ft_strjoin(char const *s1, char const *s2);
// split
char	**ft_split(char const *s, char c);
// itoa
char	*ft_itoa(int n);
// strmapi
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// striteri
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// putfd
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
// bonus struct
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
// bonus functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
