/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:12:16 by juan-anm          #+#    #+#             */
/*   Updated: 2023/08/07 00:08:36 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*//////////    INCLUDE LIBS \\\\\\\\\\*/

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

/*//////// GNL BUFFER DEFINITION \\\\\\\\\\\\*/	

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 5 
# endif

/*////////////////  First Part  \\\\\\\\\\\\\\\\\*/

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

/*////////////////!!!!!!   BONUS  !!!!!\\\\\\\\\\\\\\\\\*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*/////////////////   FT_PRINT    !!!!!!!!!////////////////\*/

int	ft_printf(const char *str, ...);
int	ft_typesort(va_list val, char c);
int	ft_putchars(char c);
int	ft_typesort(va_list val, char c);
int	ft_putstrs(char *str);
int	ft_putnbrs(long long int n, int cont);
int	ft_base_cnvrt(unsigned int nbr, char x);
int	ft_base_pointer(unsigned long long pntr);
int	ft_unsputnbrs(long long int n, int cont);

/*/////////////////   GetNextLine    !!!!!!!!!////////////////\*/

char	*ft_read_return_line(char *buffer, int fd);
char	*ft_newline(char *buffer);
void	*ft_freegnl(char	**str);
char	*ft_newline(char *buffer);
char	*ft_cleanbuffer(char *buffer, char *newline);
char	*ft_strjoingnl(char *storage, char *buffer);
char	*ft_strchrgnl(char *s, int c);
int		ft_strlengnl(char *s);
char	*get_next_line(int fd);

#endif
