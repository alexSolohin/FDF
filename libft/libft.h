/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:06:57 by lliza             #+#    #+#             */
/*   Updated: 2020/01/28 16:37:48 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>

/*
** <============================ memory ==============================>
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memalloc(size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
/*
** <========================= end of memory ===========================>
*/
/*
** <============================== char ===============================>
*/
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
/*
** <========================== end of char ============================>
*/
/*
** <============================= string ==============================>
*/
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *src, const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_atoi(const char *str);
long long		ft_atoi_base(const char *str, int base);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
/*
** <========================= end of string ==========================>
*/
/*
** <============================== num ===============================>
*/
size_t			ft_num_len(long long num, int base);
size_t			ft_unsigned_num_len(unsigned long long num, unsigned int base);
long long		ft_num_to_power(long long num, int power);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
/*
** <=========================== end of num ===========================>
*/
/*
** <========================== conversion ============================>
*/
/*
** <======================= end ofconversion =========================>
*/
/*
** <============================== list ==============================>
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new_lst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
** <=========================== end of list ==========================>
*/
/*
** <========================== my functions ==========================>
*/
char			*ft_strrev(const char *s);
size_t			ft_lstlen(t_list *head);
t_list			*ft_lstcpy(t_list *lst);
void			ft_strcpy_reverse(char *dest, char *src);
void			ft_erase_node_content(void *node, size_t node_size);
int				ft_factorial(int n);
int				ft_sqrt(int n);
/*
** <============================ bs_tree =============================>
*/
typedef struct	s_bs_tree_node
{
	int						key;
	char					*s_content;
	struct s_bs_tree_node	*left;
	struct s_bs_tree_node	*right;
}				t_bst_node;
t_bst_node		*ft_bst_create_node(int key, char *content);
t_bst_node		*ft_bst_find_node(t_bst_node *tree, int key);
void			ft_bst_insert_node(t_bst_node **tree, int key, char *content);
/*
** <======================== end of bs_tree ==========================>
*/
/*
** <===================== end of my functions ========================>
*/
#endif
