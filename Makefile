NAME_SERVER = server
NAME_CLIENT = client

all:
	@gcc -Wall -Wextra -Werror server.c -o $(NAME_SERVER)
	@gcc -Wall -Wextra -Werror client.c -o $(NAME_CLIENT)

clean:
	@rm -f server
	@rm -f client


fclean: clean

re: fclean all