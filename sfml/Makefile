SFML	=	lib_nibbler_sfml.so

SSRC	=	Tools.cpp GL.cpp

SOBJ	=	$(SSRC:.cpp=.o)

SFLAG	=	-lsfml-graphics -lsfml-window -lsfml-system

NFLAG	=	-Wall -Werror -Wextra

CC		=	g++

RM		=	rm -f

all:		$(SFML)

$(SFML):
	$(CC) -fPIC -c -o Tools.o Tools.cpp $(NFLAG)
	$(CC) -fPIC -c -o GL.o GL.cpp $(NFLAG)
	$(CC) -shared -o $(SFML) $(SOBJ) $(SFLAG)
	
clean:
	$(RM) $(SOBJ)

fclean:		clean
	$(RM) $(SFML)

re:			fclean all
