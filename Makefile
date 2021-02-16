#
# In order to execute this "Makefile" just type "make"
#

OBJS	 = main.o GameGenerics.o Tetris.o
SOURCE	 = main.cpp GameGenerics.cpp Tetris.cpp
HEADER	 = GameGenerics.h Tetris.h
OUT	 = Tetris
CC	 = g++
FLAGS	 = -g -c -Wall -Iinclude/
LFLAGS	 = -lsfml-graphics -lsfml-window -lsfml-system
YFLAGS   =
# LFLAGS - Extra flags for lex
# YFLAGS - Extra flags for yacc
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)	
	doxygen GameDocs_Configs
	echo "Done"


# create/compile the individual files >>separately<<
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

GameGenerics.o: GameGenerics.cpp
	$(CC) $(FLAGS) GameGenerics.cpp -std=c++11

Tetris.o: Tetris.cpp
	$(CC) $(FLAGS) Tetris.cpp -std=c++11


# clean up
clean:
	rm -f $(OBJS) $(OUT)
	rm -rf Docs
