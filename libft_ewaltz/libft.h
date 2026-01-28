/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:05:12 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/20 15:26:05 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_printf(const char *str, ...);
int			ft_router(const char spec, va_list *args);
int			ft_printf_char(va_list *args);
int			ft_printf_string(va_list *args);
int			ft_printf_ptr(va_list *args);
int			ft_printf_int(va_list *args);
int			ft_printf_unsigned(va_list *args);
int			ft_printf_hexa_low(va_list *args);
int			ft_printf_hexa_up(va_list *args);
int			ft_putnbr_base(unsigned long nbr);
int			ft_putnbr_base_low(unsigned long nbr);
int			ft_putnbr_base_up(unsigned long nbr);
void		ft_putnbr(int n);
void		ft_putnbr_unsigned(unsigned int n);
long		ft_int_len(long nbr);
int			ft_int_len_unsigned(unsigned int nbr);
char		*get_next_line(int fd);
char		*read_buffer(char *rest, int bytes, char *buffer, int fd);
char		*check_params(int fd);
int			get_index(char *str);
char		*get_rest(char *str, int start);
char		*str_join(char *rest, char *buffer);

#endif
