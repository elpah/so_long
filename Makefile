SRCSDIR		=	src
SRCS        = $(SRCSDIR)/main.c $(SRCSDIR)/so_long_utils.c $(SRCSDIR)/checker.c $(SRCSDIR)/graphic_launch.c $(SRCSDIR)/moves.c $(SRCSDIR)/init_map.c \
			  $(SRCSDIR)/free_map.c $(SRCSDIR)/checker_utils.c $(SRCSDIR)/graphic_utils.c $(SRCSDIR)/moves_2.c
LIBFTDIR    = ./libft
PRINTFDIR    = ./printf
GNLDIR      = ./gnl
MLXDIR      = ./minilibx-linux

LIBFT       = $(LIBFTDIR)/libft.a
PRINTF      = $(PRINTFDIR)/ft_printf.a
GNL         = $(GNLDIR)/gnl.a
MLX         = $(MLXDIR)/libmlx_Linux.a 

LIBS        = $(GNL) $(LIBFT) $(PRINTF) $(MLX) 

OBJS        = $(SRCS:.c=.o)

CC          = cc  
RM          = rm -f
CCFLAGS     = -Wall -Werror -Wextra -I$(MLXDIR) -g
MLXFLAGS    = -L/usr/X11/lib -lX11 -lXext -lm

NAME        = so_long

 %.o: 		%.c
			$(CC) $(CCFLAGS) -c $< -o $@

all:        $(LIBFT) $(PRINTF) $(GNL) $(MLX) $(NAME)

$(LIBFT):
			make -C $(LIBFTDIR)

$(PRINTF):
			make -C $(PRINTFDIR)

$(GNL):
			make -C $(GNLDIR)

$(MLX):
			make -C $(MLXDIR)

$(NAME):    $(OBJS) $(LIBS)
			$(CC) $(CCFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)
			make -C $(LIBFTDIR) clean
			make -C $(PRINTFDIR) clean
			make -C $(GNLDIR) clean
			make -C $(MLXDIR) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFTDIR) fclean
			make -C $(PRINTFDIR) fclean
			make -C $(GNLDIR) fclean
			$(RM) $(MLXDIR)/libmlx_Linux.a  # Remove only the Linux version if necessary

re:			fclean all

.PHONY:		all clean fclean re
