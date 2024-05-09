CC = gcc
CFLAG = -Wall -Wextra -Werror
CLIENT = client
SRC = client.c server.c 
OBJ = (SRC.c=.o)


all : $(CLIENT)


$(CLIENT) : $(OBJ)
	$(CC) $(CFLAG) -o $(CLIENT) $(OBJ)