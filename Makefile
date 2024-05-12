CC = gcc
CFLAG = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
SRC_C = client.c
SRC_S = server.c
SRC_C_BONUS = client_bonus.c
SRC_S_BONUS = server_bonus.c server_utils.c
OBJC = $(SRC_C:.c=.o)
OBJS = $(SRC_S:.c=.o)
OBJC_BONUS = $(SRC_C_BONUS:.c=.o)
OBJS_BONUS = $(SRC_S_BONUS:.c=.o)

all : $(CLIENT) $(SERVER)

bonus :$(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT) : $(OBJC)
	$(CC) $(CFLAG) -o $(CLIENT) $(OBJC)
$(SERVER) : $(OBJS)
	$(CC) $(CFLAG) -o $(SERVER) $(OBJS)

$(CLIENT_BONUS) : $(OBJC_BONUS)
	$(CC) $(CFLAG) -o $(CLIENT_BONUS) $(OBJC_BONUS)
$(SERVER_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAG) -o $(SERVER_BONUS) $(OBJS_BONUS)
clean :
	rm -f $(OBJC) $(OBJS) $(OBJC_BONUS) $(OBJS_BONUS)
fclean : clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re : clean all

.PHONY : all clean fclean re