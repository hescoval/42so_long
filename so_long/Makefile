NAME = so_long
CC = cc -g -Wall -Wextra -Werror 
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SRCS = *.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cc -o $(NAME) $(OBJS) $(LIBFT) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) 

$(OBJS): $(SRCS)
	$(CC) -c $(SRCS)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean	
	$(MAKE)