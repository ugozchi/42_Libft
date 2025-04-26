# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -MMD -MP
RM = rm -rf
AR = ar rcs

# Colors (When you change colors or styles using echo, you need to RESET the parameters at the end of the sentence.)
RESET	=	\033[0m
BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[1;35m
CYAN	=	\033[1;36m
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
SRCS		=	Char/Analysis/ft_isalnum.c \
				Char/Analysis/ft_isalpha.c \
				Char/Analysis/ft_isascii.c \
				Char/Analysis/ft_isdigit.c \
				Char/Analysis/ft_isprint.c \
				Char/Analysis/ft_isspace.c \
				Char/Analysis/ft_isupper.c \
				Char/Manipulation/ft_tolower.c \
				Char/Manipulation/ft_toupper.c \
				Conversion/ft_atoi.c \
				Conversion/ft_itoa.c \
				Fd_Manager/ft_putchar_fd.c \
				Fd_Manager/ft_putendl_fd.c \
				Fd_Manager/ft_putnbr_fd.c \
				Fd_Manager/ft_putstr_fd.c \
				Free/ft_free_and_set_to_null.c \
				List/ft_lstadd_back.c \
				List/ft_lstadd_front.c \
				List/ft_lstclear.c \
				List/ft_lstdelone.c \
				List/ft_lstiter.c \
				List/ft_lstlast.c \
				List/ft_lstmap.c \
				List/ft_lstnew.c \
				List/ft_lstsize.c \
				Maths/ft_abs.c \
				Maths/ft_max.c \
				Maths/ft_min.c \
				Maths/ft_square.c \
				Memory/ft_bzero.c \
				Memory/ft_calloc.c \
				Memory/ft_memchr.c \
				Memory/ft_memcmp.c \
				Memory/ft_memcpy.c \
				Memory/ft_memmove.c \
				Memory/ft_memset.c \
				Pointer/ft_swap.c \
				String/Analysis/ft_is_just_space.c \
				String/Analysis/ft_strchr.c \
				String/Analysis/ft_strcmp.c \
				String/Analysis/ft_strlen.c \
				String/Analysis/ft_strncmp.c \
				String/Analysis/ft_strnstr.c \
				String/Analysis/ft_strrchr.c \
				String/Manipulation/ft_concate.c \
				String/Manipulation/ft_print_data.c \
				String/Manipulation/ft_printf.c \
				String/Manipulation/ft_split_whitespace.c \
				String/Manipulation/ft_split.c \
				String/Manipulation/ft_strdup.c \
				String/Manipulation/ft_striteri.c \
				String/Manipulation/ft_strjoin.c \
				String/Manipulation/ft_strlcat.c \
				String/Manipulation/ft_strlcpy.c \
				String/Manipulation/ft_strmapi.c \
				String/Manipulation/ft_strncpy.c \
				String/Manipulation/ft_strtod_utils.c \
				String/Manipulation/ft_strtod.c \
				String/Manipulation/ft_strtok.c \
				String/Manipulation/ft_strtrim.c \
				String/Manipulation/ft_substr.c \
				String/Manipulation/get_next_line.c 



SRC_COUNT	=	${words ${SRCS}}

# OBJS		=	$(addprefix ${OBJ_DIR}/, $(notdir $(SRCS:.c=.o)))
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

OBJ_DIR		=	.o

all:			${OBJ_DIR} ${NAME}

${NAME}:		entry_message ${OBJS}
				@if [ -e ${NAME} ] && [ "$(shell find ${OBJ_DIR} -newer ${NAME} 2>/dev/null)" = "" ]; then \
					echo "${YELLOW}${INFO} Nothing to do !${RESET}"; \
				else \
					echo "${GREEN} DONE${RESET}"; \
					${AR} ${NAME} ${OBJS} && echo "${CYAN}Creating ${NAME} archive file${RESET}"; \
					echo "${PURPLE}${NAME} created${RESET}"; \
				fi

${OBJ_DIR}:
				@if [ ! -d "${OBJ_DIR}" ]; \
				then mkdir -p "${OBJ_DIR}"; \
				fi

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN}${OK}${RESET}"
        
clean:
			@if [ ! -d "${OBJ_DIR}" ]; \
			then \
				echo "${YELLOW}${INFO} Repo .o already clean${RESET}"; \
			else \
				echo "${RED}Removing all .o files${RESET}"; \
				${RM} ${OBJ_DIR}; \
			fi

fclean:			clean
			@if [ ! -f "${NAME}" ]; \
			then \
				echo "${YELLOW}${INFO} Archive file already clean${RESET}"; \
			else \
				echo "${RED}Removing archive files${RESET}"; \
				${RM} ${NAME}; \
			fi

re:				fclean all

entry_message:
				@echo "${YELLOW}${INFO} ${SRC_COUNT} files of the library:\n${GREEN}Compilation :${RESET}"

.PHONY:			all clean fclean re entry_message

# Inclusion des fichiers de dépendances
-include $(DEPS)