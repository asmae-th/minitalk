CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
SRC_C = client.c
SRC_S = server.c utils.c
SRC_C_BONUS = client_bonus.c
SRC_S_BONUS = server_bonus.c server_utils.c utils.c
OBJC = $(SRC_C:.c=.o)
OBJS = $(SRC_S:.c=.o)
OBJC_BONUS = $(SRC_C_BONUS:.c=.o)
OBJS_BONUS = $(SRC_S_BONUS:.c=.o)

all : $(CLIENT) $(SERVER)

bonus :$(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT) : $(OBJC)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJC)
$(SERVER) : $(OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS)

$(CLIENT_BONUS) : $(OBJC_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(OBJC_BONUS)
$(SERVER_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJS_BONUS)
clean :
	rm -f $(OBJC) $(OBJS) $(OBJC_BONUS) $(OBJS_BONUS)
fclean : clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re : clean all bonus

.PHONY : all clean fclean re bonus