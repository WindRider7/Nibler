GTK		=	lib_nibbler_gtk.so

GSRC	=	Tools.cpp GTK.cpp

GOBJ	=	$(GSRC:.cpp=.o)

GFLAG	=	`pkg-config --cflags --libs gtk+-2.0`

NFLAG	=	-Wall -Werror -Wextra

CC		=	g++

RM		=	rm -f

all:		$(GTK)

$(GTK):
	$(CC) -fPIC -c -o Tools.o Tools.cpp $(NFLAG) $(GFLAG)
	$(CC) -fPIC -c -o GTK.o GTK.cpp $(NFLAG) $(GFLAG)
	$(CC) -shared -o $(GTK) $(GOBJ) $(GFLAG)
	
clean:
	$(RM) $(GOBJ)

fclean:		clean
	$(RM) $(GTK)

re:			fclean all
