/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:04:03 by yliu              #+#    #+#             */
/*   Updated: 2023/12/11 17:37:08 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <limits.h>
#include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define MAX_CHAR 256

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// is-group
int					ft_isalnum(int i);
int					ft_isalpha(int i);
int					ft_isascii(int i);
int					ft_isdigit(int i);
int					ft_isprint(int i);

// mem-group
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *s, int c, size_t len);

// to-group
int					ft_tolower(int i);
int					ft_toupper(int i);
int					ft_atoi(const char *str);

// str-group
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *str, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strchr(const char *s, int i);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);

// put-group
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// lst-group
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new_node);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst_ptr, void (*del)(void *));
void				ft_lstiter(t_list *tlist_ptr, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst_ptr, void *(*f)(void *),
						void (*del)(void *));

// newly added after libft
// TODO: null check
// TODO: lstaddback with is_sentinel++

// doubly_linked_list(dl_list)
// define the generalized structure of doubly linked list,
// hense set with none-domain specific name.
typedef struct s_node	t_dl_lst;

typedef struct s_node {
	int			int_data;
	size_t		is_sentinel;
	t_dl_lst	*next_p;
	t_dl_lst	*prev_p;
}				t_dl_lst;

// ft_dl_lst
t_dl_lst			*ft_dl_lstcreate(int content, size_t is_sentinel);
t_dl_lst			*ft_dl_lstnew(int content);
void				ft_dl_lstadd_front(t_dl_lst **lst, t_dl_lst *new_node);
size_t				ft_dl_lstsize(t_dl_lst *lst);
t_dl_lst			*ft_dl_lstlast(t_dl_lst *lst);
void				ft_dl_lstadd_back(t_dl_lst **lst, t_dl_lst *new_node);

void				ft_dl_lstdelone(t_dl_lst *lst, void (*del)(void *));
void				ft_dl_lstclear(t_dl_lst **lst_ptr, void (*del)(void *));
// iter
// lstmap

// debug func
void				ft_dl_pf_lst(t_dl_lst *lst);

#endif
