CORE	=	nibbler

SFML	=	lib_nibbler_sfml.so

CSRC	=	./core/Core.cpp ./core/Parser.cpp ./core/Timer.cpp \
			./core/Tools.cpp ./core/main.cpp

SSRC	=	./sfml/Tools.cpp ./sfml/GL.cpp

COBJ	=	$(CSRC:.cpp=.o)

SOBJ	=	$(SSRC:.cpp=.o)

SFLAG	=	-lsfml-graphics -lsfml-window -lsfml-system

NFLAG	=	-Wall -Werror -Wextra

CC		=	g++

RM		=	rm -f

all:		$(SFML) $(CORE)

$(SFML):
	$(CC) -fPIC -c -o ./sfml/Tools.o ./sfml/Tools.cpp $(NFLAG)
	$(CC) -fPIC -c -o ./sfml/GL.o ./sfml/GL.cpp $(NFLAG)
	$(CC) -shared -o $(SFML) $(SOBJ) $(SFLAG)
	
$(CORE):	$(COBJ)
	$(CC) -o $(CORE) $(COBJ) $(NFLAG) -ldl

clean:
	$(RM) $(COBJ) $(SOBJ)

fclean:		clean
	$(RM) $(CORE) $(SFML)

re:			fclean all
