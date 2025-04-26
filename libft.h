/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:43:20 by uzanchi           #+#    #+#             */
/*   Updated: 2025/04/26 19:02:53 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*Library*/

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>

/*Define for Ft_Printf*/

# define DEC_BASE "0123456789"
# define HEX_BASE_LOW "0123456789abcdef"
# define HEX_BASE_HIGH "0123456789ABCDEF"
# define POINTER_PREFIX "0x"
# define NULL_DISPLAY "(null)"
# define NIL_DISPLAY "(nil)"

/*Define buffer and fd for Get_Next_line*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

/*Definition of structure for Libft_bonus*/

typedef struct s_list_bonus
{
	void				*content;
	struct s_list_bonus	*next;
	struct s_list_bonus	*prev;
}						t_list_bonus;

/*Libft main part*/

/******      CHAR      ******\
\****************************/
/*    Analysis    */
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isnumeric(char *str);
int						ft_isprint(int c);
int						ft_isspace(int c);

/*  Manipulation  */
int						ft_toupper(int c);
int						ft_tolower(int c);

/******   CONVERSION   ******\
\****************************/
int						ft_atoi(const char *nptr);
char					*ft_itoa(int n);

/******   FD_MANAGER   ******\
\****************************/
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);

/*******     FREE     *******\
\****************************/

void					free_and_set_to_null(size_t n, ...);

/*******     LIST     *******\
\****************************/
t_list_bonus			*ft_lstnew(void *content);
void					ft_lstadd_front(t_list_bonus **alst, t_list_bonus *new);
int						ft_lstsize(t_list_bonus *lst);
t_list_bonus			*ft_lstlast(t_list_bonus *lst);
void					ft_lstadd_back(t_list_bonus **lst, t_list_bonus *new);
void					ft_lstdelone(t_list_bonus *lst, void (*del)(void *));
void					ft_lstclear(t_list_bonus **lst, void (*del)(void *));
void					ft_lstiter(t_list_bonus *lst, void (*f)(void *));
t_list_bonus			*ft_lstmap(t_list_bonus *lst, void *(*f)(void *),
							void (*del)(void *));

/*******     MATHS    *******\
\****************************/
int						abs(int nb);
double					square(double x);
int						ft_min(int a, int b);
int						ft_max(int a, int b);

/*******    MEMORY    *******\
\****************************/
void					ft_bzero(void *str, size_t n);
void					*ft_calloc(size_t count, size_t size);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t length);
void					*ft_memset(void *str, int value, size_t n);

/*******    POINTER    ******\
\****************************/

void					ft_swap(int *a, int *b);

/*******    STRING    *******\
\****************************/
/*    Analysis    */
int						ft_is_just_space(char *str);
char					*ft_strchr(const char *str, int c);
int						ft_strcmp(const char *s1, const char *s2);
size_t					ft_strlen(const char *str);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
char					*ft_strrchr(const char *str, int c);

/*  Manipulation  */
char					*ft_concate(size_t n, ...);
int						ft_printf(const char *str, ...);
int						ft_printf_colour(char *colour, const char *str, ...);
size_t					putchar_count(int c);
size_t					putstr_count(char *str);
size_t					putnbr_base10_count(int nbr, char *base);
size_t					put_u_base10_count(unsigned int nbr, char *base);
size_t					putptr_base_count(void *ptr, char *base,
							int first_loop_flag);
char					**ft_split_whitespace(const char *str);
char					**ft_split(char const *s, char c);
char					*ft_strdup(const char *src);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
char					*ft_strncpy(char *dest, const char *src, size_t n);
double					ft_strtod(const char *nptr, char **endptr);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*get_next_line(int fd);

#endif
