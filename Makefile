CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
BONUS_NAME = checker

O_DIR = .objs

S_DIR = srcs

CHCKR = chckr/checker.c chckr/checker_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
PSWP = srcs/push_swap.c srcs/quicksort.c

SRCS = 	libft/ft_atoi.c libft/ft_lstsize.c libft/ft_strlcpy.c libft/ft_strncmp.c \
		libft/ft_lstadd_back.c libft/ft_lstlast.c libft/ft_split.c libft/ft_strlen.c \
		libft/ft_lstbeforelast.c libft/ft_lstnew_int.c libft/ft_strjoin.c \
		srcs/cost_finder.c srcs/free.c \
		srcs/cost_finder_utils.c srcs/operations.c srcs/quickselect.c srcs/quicksort_utils.c \
		srcs/cost_finder_utils_deux.c srcs/operations_suite.c srcs/quickselect_utils.c \
		srcs/cost_finder_utils_trois.c srcs/parsing.c srcs/quickselect_utils_leretour.c \
		srcs/operations_check.c srcs/operations_suite_check.c

OBJS = $(addprefix $(O_DIR)/, $(SRCS))
MAIN_OBJ = $(addprefix $(O_DIR)/, $(PSWP:.c=.o))
BONUS_OBJ = $(addprefix $(O_DIR)/, $(CHCKR:.c=.o))

OBJS := $(OBJS:.c=.o)

$(O_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I./hdrs/ -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	@$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME)

$(BONUS_NAME): $(OBJS) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJ) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean : 
	rm -rf $(O_DIR)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : all bonus clean fclean re
