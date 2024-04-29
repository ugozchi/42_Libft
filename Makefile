# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf
AR = ar rcs

# Colors (When you change colors or styles using echo, you need to RESET the parameters at the end of the sentence.)
RESET	=	\033[0m
BLACK	=	\033[0;30m
RED	=	\033[1;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m

# Styles (To change a style, you have to change the "0" after the open square bracket "[" in "Colors" to the following numbers.)
# NORMAL = 0
# BOLD = 1
# LOW INTENSITY = 2
# ITALIC = 3
# UNDERLINED = 4
# BLINKING = 5
# INVERTED/UNDERLINE = 7
# HIDDEN = 8
# CROSSED OUT = 9 

# Symbols
OK	=	✓
FAIL	=	✗
INFO	=	ⓘ

# Sources and Objects
SRC = ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_strlen \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memmove \
	ft_strlcpy \
	ft_strlcat \
	ft_toupper \
	ft_tolower \
	ft_strchr \
	ft_strrchr \
	ft_strncmp \
	ft_memchr \
	ft_memcmp \
	ft_strnstr \
	ft_atoi \
	ft_calloc \
	ft_strdup \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_itoa \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd
BONUS_SRC = ft_lstnew \
	ft_lstadd_front \
	ft_lstsize \
	ft_lstlast \
	ft_lstadd_back \
	ft_lstdelone \
	ft_lstclear \
	ft_lstiter \
	ft_lstmap  

SRCS = ${addsuffix .c, ${SRC}}
OBJS = ${addsuffix .o, ${SRC}}
BONUS_SRCS = ${addsuffix .c, ${BONUS_SRC}}
BONUS_OBJS = ${addsuffix .o, ${BONUS_SRC}}

.c.o: 
	${CC} ${CFLAGS} -c -o $@ $<

$(NAME): ${OBJS}
	${AR} $@ $^

bonus: ${OBJS} ${BONUS_OBJS}
	${AR} ${NAME} $^

all: $(NAME)

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
