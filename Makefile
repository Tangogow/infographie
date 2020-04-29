NAME    = 	opengl
CC			= 	g++ -w
RM			= 	rm -f
SRC    	= 	src/*.cpp
OBJ			= 	$(SRC:.c=.o)
INC			=		-Iinclude
LDFLAGS = 	-lglut -lGLU -lSOIL -lGL

all:	$(NAME)

$(NAME):
		$(CC) -o $(NAME) $(SRC) $(INC) $(LDFLAGS)

clean:
		$(RM) $(NAME) $(SRC)/*.o

re:		clean all
