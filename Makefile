# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f
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
SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

OBJS		=	${SRCS:.c=.o}

BONUS_SRCS	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

bonus:		${BONUS_OBJS}
			ar rcs ${NAME} ${BONUS_OBJS}

re:			fclean all

.PHONY:		all clean fclean re bonus
