/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: plamtenz <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 20:36:08 by plamtenz     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 01:00:43 by plamtenz    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef unsigned long	t_size;

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

int						ft_atoi(const char *str);
void					ft_bzero(void *str, t_size n);
void					*ft_calloc(t_size nitems, t_size n);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
void					ft_swap(t_size a, t_size b);
char					*ft_itoa(int n);
void					*ft_memccpy(void *dest, const void *src, int c,
		t_size n);
void					*ft_memchr(const void *str, int c, t_size n);
int						ft_memcmp(const void *s1, const void *s2, t_size n);
void					*ft_memcpy(void *s1, const void *s2, t_size n);
void					*ft_memmove(void *dest, const void *src, t_size n);
void					*ft_memset(void *str, int c, t_size n);
char					*ft_strchr(const char *str, int c);
char					*ft_strrchr(const char *str, int c);
char					*ft_strdup(const char *src);
t_size					ft_strlcat(char *dest, const char *src, t_size n);
t_size					ft_strlcpy(char *dest, const char *src, t_size size);
t_size					ft_strlen(const char *str);
char					*ft_strmapi(char const *s,
		char (*f) (unsigned int, char));
int						ft_strncmp(const char *s1, const char *s2, t_size n);
char					*ft_strnstr(const char *s1, const char *s2, t_size n);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_substr(char const *s, unsigned int start,
		t_size len);
int						ft_tolower(int c);
int						ft_toupper(int c);
char					*ft_strjoin(char const *s1, char const *s2);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **alst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **alst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del) (void *));
void					ft_lstclear(t_list **lst, void (*del) (void *));
void					ft_lstiter(t_list *lst, void (*f) (void *));
t_list					*ft_lstmap(t_list *lst, void *(*f) (void *),
		void (*del)(void *));
char					*ft_strcat(char *dest, const char *src);

#endif
