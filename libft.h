#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

int	ft_isalpha(int c);	// check ok / regarde si c -> alpha
int	ft_isdigit(int c);	// check ok / regarde si c -> [0-9]
int	ft_isalnum(int c);	// check ok / regarde si c -> alpha ou num
int	ft_isascii(int c);	// check ok / regarde si c -> dans la table
int	ft_isprint(int c);	// check ok / regarde si c -> imprimable
size_t	ft_strlen(const char *str); // check ok / calcul longueur string
void	*ft_memset(void *str, int value, size_t n); // check ok / initialise zone memoire avec valeur specifique
void	ft_bzero(void *str, size_t n); // check ok / initialise zone memoire avec des '0'
void	*ft_memcpy(void *dest, const void *src, size_t n); // check ok / copie chaine de car de src vers dest avec longueur n
void	*ft_memmove(void *dest, const void *src, size_t length); // check ok / copie sequence octets d'une zone mem src vers dest meme si chevauche
size_t	ft_strlcpy(char *dest, const char *src, size_t size); // check ok / effectue une copie sécurisé d'une chaine de car et renvoie la longueur de la chaine copié 
size_t	ft_strlcat(char *dest, const char *src, size_t size); // CHECK KO !!! / ajoute chaine de char src à la fin de dest avec un NULL
int	ft_toupper(int c); // check ok / mets minuscule en majuscule
int	ft_tolower(int c); // check ok / mets majuscule en minuscule
char	*ft_strchr(const char *str, int c); // check ok / repere la 1er occurence de c dans str
char	*ft_strrchr(const char *str, int c); // check ok / repere la derniere occurence de c dans str
int	ft_strncmp(const char *s1, const char *s2, size_t n); // check ok / compare de string, si differentes retourne la diff ascii en les 2 char
void	*ft_memchr(const void *s, int c, size_t n); // check ok / cherche occurence octet particulier dans zone memoire donnée
int	ft_memcmp(const void *s1, const void *s2, size_t n); // check ok / compare 2 blocs de memoire et retourn la differn*ence entre 2 octets si elle existe 
char	*ft_strnstr(const char *haystack, const char *needle, size_t len); // check ok / cherche premiere occurence d'une sous chaine dans une chaine en limitant la recherche a n char
int	ft_atoi(const char *nptr); // check ok / transforme chaine de char numerique en int
void	*ft_calloc(size_t count, size_t size); // check ok / alloue de la memoire pour un tableau d'elements de taille specifie et init à 0. Retourne pointeur vers memoire alloue
char	*ft_strdup(const char *src); // check ok / duplique une chaine de char en la malloc qui peut etre free

#endif
