/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:45:21 by rkamegne          #+#    #+#             */
/*   Updated: 2019/05/08 20:41:22 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# define TYPES "%cfspdiouUxXb"
# define BUFF_SIZE 1
# ifndef OPEN_MAX
#  define OPEN_MAX 4986
# endif

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct		s_conv
{
	char			c;
	int				padding;
	int				precision;
	char			size;
	int				h;
	int				m;
	int				p;
	int				z;
	int				s;
	int				count;
	int				base;
	int				take;
}					t_conv;

int				get_next_line(const int fd, char **line);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
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
char			*ft_itoa(long long n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_cislower(int c);
int				ft_cisupper(int c);
int				ft_cisspace(int c);
int				ft_strlen_err(const char *str);
int				ft_sqrt(int nb);
char			*ft_replace(char *str, int c, int b);
int				ft_count_words(const char *str, char c);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
char			*ft_strdup_at(char *str, char c);
int				ft_atoi_base(const char *str, int str_base);
int				ft_ispace(char c);
char			*ft_strchr_alpha(const char *s, int c);
char			*ft_strccpy(char *src, int len);
char			*ft_str_putchar(int c, int len);
char			*ft_utoa(unsigned long long n);
long long		ft_abs(long long n);
char			*ft_utoa_base(unsigned long long n, int base, int maj, int len);
int				ft_nb_len(unsigned long long n, int base);
char			*ft_itoa_base(long long n, int base, int maj, int len);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strcat_free(char *s1, char *s2);
int				ft_init(t_conv **type);
int				ft_patoi(char *str, int *offset);
void			ft_putrev_char(unsigned char c, char *str, t_conv *type);
void			ft_putrev_str(char *str, char *strp, t_conv *type);
void			ft_putnull(t_conv *type);
void			ft_padding_no_preu(uintmax_t val, t_conv *type,
														char *str, int len);
void			ft_padding_preu(t_conv *type, char *str);
void			ft_padding_no_pre(char *sign, t_conv *type, char *str);
void			ft_convert_float(long double nbr, t_conv *type);
intmax_t		ft_size_signed(t_conv *type, va_list arg);
uintmax_t		ft_size_unsigned(t_conv *type, va_list arg);
void			convert_unsigned(uintmax_t val, t_conv *type);
void			ft_fetch_arg(t_conv *type, va_list arg);
void			ft_fetch_arg2(t_conv *type, va_list arg);
void			ft_fetch_arg3(t_conv *type, va_list arg);
int				ft_parse(const char *restrict format, va_list arg);
int				ft_printf(const char *restrict format, ...);
#endif