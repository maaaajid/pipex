NAME = pipex

SRCS = pipex.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_substr.c pipex_utils.c

CFLAGS = -Wall -Wextra -Werror

RM = rm -fr

all : $(NAME)

$(NAME) : $(SRCS)
	@CC $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	@$(RM) $(NAME)

fclean : 
	@$(RM) $(NAME)

re : fclean all