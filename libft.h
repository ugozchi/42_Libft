#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int	ft_isalpha(int c); // regarde si c -> alpha
int	ft_isdigit(int c); // regarde si c -> [0-9]
int	ft_isalnum(int c); // regarde si c -> alpha ou num
int	ft_isascii(int c); // regarde si c -> dans la table
int	ft_isprint(int c); // regarde si c -> imprimable
size_t	ft_strlen(const char *str); // calcul longueur string
void	*ft_memset(void *str, int value, size_t n); // initialise zone memoire avec valeur specifique
void	ft_bzero(void *str, size_t n); // initialise zone memoire avec des '0'
void	*ft_memcpy(void *dest, const void *src, size_t n); // copie chaine de car de src vers dest avec longueur n
void	*ft_memmove(void *dest, const void *src, size_t length); // copie sequence octets d'une zone mem src vers dest meme si chevauche
size_t	ft_strlcpy(char *dest, const char *src, size_t size); // effectue une copie sécurisé d'une chaine de car et renvoie la longueur de la chaine copié 
size_t	ft_strlcat(char *dest, const char *src, size_t size); // ajoute chaine de char src à la fin de dest avec un NULL
int	ft_toupper(int c); // mets minuscule en majuscule
int	ft_tolower(int c); // mets majuscule en minuscule
char	*ft_strchr(const char *str, int c); // repere la 1er occurence de c dans str
char	*ft_strrchr(const char *str, int c); // repere la derniere occurence de c dans str
int	ft_strncmp(const char *s1, const char *s2, size_t n); // compare de string, si differentes retourne la diff ascii en les 2 char
void	*ft_memchr(const void *s, int c, size_t n); // cherche occurence octet particulier dans zone memoire donnée
int	ft_memcmp(const void *s1, const void *s2, size_t n); // compare 2 blocs de memoire et retourn la differn*ence entre 2 octets si elle existe 
char	*ft_strnstr(const char *big, const char *little, size_t len); // cherche premiere occurence d'une sous chaine dans une chaine en limitant la recherche a n char
int	ft_atoi(const char *nptr); // transforme chaine de char numerique en int
void	*ft_calloc(size_t count, size_t size); // alloue de la memoire pour un tableau d'elements de taille specifie et init à 0. Retourne pointeur vers memoire alloue
char	*ft_strdup(const char *src); // duplique une chaine de char en la malloc qui peut etre free
char	*ft_substr(char const *s, unsigned int start, size_t len); // alloue et retourne une chaine de char issue de la chaine s, chaine commence a start et a pour taille len
char	*ft_strjoin(char const *s1, char const *s2); // alloue et retourne une chaine de char resultant de s1 et s2
char	*ft_strtrim(char const *s1, char const *set); // alloue et retourne copie de chaine s1 sans char set au début et à la fin
char	**ft_split(char const *s, char c); // alloue et retourne un tab de chaine de char obtenue en separant s à l'aide de c
char	*ft_itoa(int n);// Transforme un int en chaine de char
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // applique la fonction f a chaque caractere d'une string
void	ft_striteri(char *s, void (*f)(unsigned int, char *)); // comme strmapi mais ne renvoi rien 
void	ft_putchar_fd(char c, int fd); // ecrit le char c sur le file descriptor donne (par exemple le terminal)
void	ft_putstr_fd(char *s, int fd); // ecrit une string sur un file descriptor donne
void	ft_putendl_fd(char *s, int fd); // comme putstr_fd mais rajoute \n a la fin
void	ft_putnbr_fd(int n, int fd); // ecrit un nombre dans une chaine de caractere sur un fd donne
t_list	*ft_lstnew(void *content); // alloue et renvoie new element et initialise content avec le parametre et le reste à NULL
void	ft_lstadd_front(t_list **alst, t_list *new); // ajoute new au début de la list 
int	ft_lstsize(t_list *lst); // compte le nombre d'element de la liste
t_list	*ft_lstlast(t_list *lst); // renvoie le dernier elements de la liste
void	ft_lstadd_back(t_list **lst, t_list *new); // ajoute element new a la fin de la liste
void	ft_lstdelone(t_list *lst, void (*del)(void *)); // libere la memoire de l'element passe en argument 
void	ft_lstclear(t_list **lst, void (*del)(void *)); // Sup et libere la mem de l'element passe en parametre et de tous ceux qui suivent et pointeur initial a NULL
void	ft_lstiter(t_list *lst, void (*f)(void *)); // Itere sur la list et applique la fonction f au contenue de chaque element
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)); // comme lstiter mais crere une nouvelle lisre resultante des application succesives de f

#endif
