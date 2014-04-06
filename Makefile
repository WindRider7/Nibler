CORE	=	nibbler

XLIB	=	lib_nibbler_xlib.so
SFML	=	lib_nibbler_sfml.so
GTK		=	lib_nibbler_gtk.so

CSRC	=	./core/Core.cpp ./core/Parser.cpp ./core/Timer.cpp \
			./core/Tools.cpp ./core/main.cpp

XSRC	=	./xlib/Tools.cpp ./xlib/Xlib.cpp
SSRC	=	./sfml/Tools.cpp ./sfml/GL.cpp
GSRC	=	./gtk/Tools.cpp ./gtk/GTK.cpp

COBJ	=	$(CSRC:.cpp=.o)

XOBJ	=	$(XSRC:.cpp=.o)
SOBJ	=	$(SSRC:.cpp=.o)
GOBJ	=	$(GSRC:.cpp=.o)

XFLAG	=	-lX11
SFLAG	=	-lsfml-graphics -lsfml-window -lsfml-system
GFLAG	=	`pkg-config --cflags --libs gtk+-2.0`

NFLAG	=	-Wall -Werror -Wextra

CC		=	g++

RM		=	rm -f

all:		$(SFML) $(XLIB) $(GTK) $(CORE)

$(SFML):
	$(CC) -fPIC -c -o ./sfml/Tools.o ./sfml/Tools.cpp $(NFLAG)
	$(CC) -fPIC -c -o ./sfml/GL.o ./sfml/GL.cpp $(NFLAG)
	$(CC) -shared -o $(SFML) $(SOBJ) $(SFLAG)

$(XLIB):
	$(CC) -fPIC -c -o ./xlib/Tools.o ./xlib/Tools.cpp $(NFLAG)
	$(CC) -fPIC -c -o ./xlib/Xlib.o ./xlib/Xlib.cpp $(NFLAG)
	$(CC) -shared -o $(XLIB) $(XOBJ) $(XFLAG)

$(GTK):
	$(CC) -fPIC -c -o ./gtk/Tools.o ./gtk/Tools.cpp $(NFLAG) $(GFLAG)
	$(CC) -fPIC -c -o ./gtk/GTK.o ./gtk/GTK.cpp $(NFLAG) $(GFLAG)
	$(CC) -shared -o $(GTK) $(GOBJ) $(GFLAG)
	
$(CORE):	$(COBJ)
	$(CC) -o $(CORE) $(COBJ) $(NFLAG) -ldl

clean:
	$(RM) $(COBJ) $(GOBJ) $(SOBJ) $(XOBJ) 

fclean:		clean
	$(RM) $(CORE) $(GTK) $(SFML) $(XLIB)

re:			fclean all
