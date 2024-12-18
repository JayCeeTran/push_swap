NAME = libpush_swap.a
LIBFT = libft.a
FPRINT = libft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

LSRCS = libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strdup.c \
	libft/ft_striteri.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_strtrim.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c \
	libft/ft_lstnew_bonus.c \
	libft/ft_lstadd_front_bonus.c \
	libft/ft_lstadd_back_bonus.c \
	libft/ft_lstclear_bonus.c \
	libft/ft_lstdelone_bonus.c \
	libft/ft_lstiter_bonus.c \
	libft/ft_lstlast_bonus.c \
	libft/ft_lstmap_bonus.c \
	libft/ft_lstsize_bonus.c \

FTP_SRCS = ft_printf/ft_printf.c \
	   ft_printf/ft_putc.c \
	   ft_printf/ft_putnbr.c \
	   ft_printf/ft_put_p.c \
	   ft_printf/ft_putstr_f.c \
	   ft_printf/ft_put_us_hex.c \

SRCS = push_swap.c \
	linked_utils.c \
	list_utils2.c \
	parse_argv_to_stack.c \

OBJ = $(SRCS:.c=.o)
LOBJ = $(LSRCS:.c=.o)
FTP_OBJ = $(FTP_SRCS:.c=.o)

EXE = a.out

$(LIBFT): $(LOBJ)
	ar -rcs $(LIBFT) $(LOBJ)

$(FPRINT): $(FTP_OBJ)
	ar -rcs $(FPRINT) $(FTP_OBJ)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

libs: $(NAME) $(LIBFT) $(FPRINT)

run: $(EXE)
	./a.out 4 2 1 4

$(EXE): $(NAME) $(LIBFT) $(FPRINT)
	cc $(CFLAGS) $(NAME) $(FPRINT) $(LIBFT) -o $(EXE)

all: $(NAME)

clean:
	rm -f $(OBJ) $(LOBJ) $(FTP_OBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT) $(FPRINT)

re: fclean all

