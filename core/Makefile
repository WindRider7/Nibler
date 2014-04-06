CORE	=	nibbler

CSRC	=	Core.cpp Parser.cpp Timer.cpp \
			Tools.cpp main.cpp

COBJ	=	$(CSRC:.cpp=.o)

NFLAG	=	-Wall -Werror -Wextra

CC		=	g++

RM		=	rm -f

all:		$(CORE)
	
$(CORE):	$(COBJ)
	$(CC) -o $(CORE) $(COBJ) $(NFLAG) -ldl

clean:
	$(RM) $(COBJ)

fclean:		clean
	$(RM) $(CORE)

re:			fclean all
