NAME			= libftprintf.a
CC				= clang
CFLAGS			= -Wall -Werror -Wextra
IFLAGS			= -I$(INCS_PATH)
AR				= ar
ARFLAGS			= rcs
RM				= rm -rf

SRCS_PATH		= srcs/
INCS_PATH		= includes
CONVS_SRCS_PATH	= converters/
FLAGS_SRCS_PATH	= flags/
LIBFT_MAKE_PATH	= ./libft
LIBFT_MAKE_CMD	= make bonus
LIBFT_MAKE_FLAG	= -C
LIBFT_LIB_NAME	= libft.a

INCS_NAME		= $(addprefix $(INCS_PATH)/, ft_printf.h)
CONVS_SRCS_NAME	= $(addprefix $(CONVS_SRCS_PATH), chars_converters.c \
				  	converters.c \
					converters_utils.c \
					decimal_converters.c)
FLAGS_SRCS_NAME	= $(addprefix $(FLAGS_SRCS_PATH), flags_utils.c)
SRCS_NAME		= $(addprefix $(SRCS_PATH), ft_printf.c \
				  	helper_utils.c \
					utils.c \
					$(CONVS_SRCS_NAME) \
					$(FLAGS_SRCS_NAME))

OBJS			= $(SRCS_NAME:.c=.o)

all				: $(NAME)

$(NAME)			: $(OBJS)
				$(LIBFT_MAKE_CMD) $(LIBFT_MAKE_FLAG) $(LIBFT_MAKE_PATH)
				cp $(LIBFT_MAKE_PATH)/$(LIBFT_LIB_NAME) $(NAME)
				$(AR) $(ARFLAGS) $@ $^

%.o				: %.c
				$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean			:
				$(RM) $(OBJS)

fclean			: clean
				make fclean $(LIBFT_MAKE_FLAG) $(LIBFT_MAKE_PATH)
				$(RM) $(NAME)

re				: fclean all

.PHONY			: all re clean fclean
