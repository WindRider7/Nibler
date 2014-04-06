XLIB	=	lib_nibbler_xlib.so

XSRC	=	Tools.cpp Xlib.cpp

XOBJ	=	$(XSRC:.cpp=.o)

XFLAG	=	-lX11

NFLAG	=	-Wall -Werror -Wextra

CC		=	g++

RM		=	rm -f

all:		$(XLIB)

$(XLIB):
	$(CC) -fPIC -c -o Tools.o Tools.cpp $(NFLAG)
	$(CC) -fPIC -c -o Xlib.o Xlib.cpp $(NFLAG)
	$(CC) -shared -o $(XLIB) $(XOBJ) $(XFLAG)
	
clean:
	$(RM) $(XOBJ)

fclean:		clean
	$(RM) $(XLIB)

re:			fclean all
