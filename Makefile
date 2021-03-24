#
# In order to execute this "Makefile" just type "make"
#
ODIR = obj
LOC = src/
OBJS	 = obj/main.o obj/GameGenerics.o obj/Tetris.o obj/Arkanoid.o obj/Snake.o
SOURCE	 = src/*.cpp
HEADER	 = *.h
OUT	 = GameBoy
CC	 = g++
FLAGS	 = -g -c -Wall -Iinclude/
LFLAGS	 = -lsfml-graphics -lsfml-window -lsfml-system
YFLAGS   =
# LFLAGS - Extra flags for lex
# YFLAGS - Extra flags for yacc
# -g option enables debugging mode 
# -c flag generates object code for separate files

##########################################
#    Don't touch anything below this     #
##########################################
all: $(OBJS)   
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	# uncomment below line if you have doxygen support to generate documentation	
	# doxygen GameDocs_Configs    
	echo "Done"
	
# dummy folder to create a directory for object files.
dummy_build_folder := $(shell mkdir -p $(ODIR))

# create/compile the individual files >>separately<<
obj/main.o: $(LOC)main.cpp
	$(CC) $(FLAGS) $(LOC)main.cpp -std=c++11 -o obj/main.o

obj/GameGenerics.o: $(LOC)GameGenerics.cpp
	$(CC) $(FLAGS) $(LOC)GameGenerics.cpp -std=c++11 -o obj/GameGenerics.o

obj/Tetris.o: $(LOC)Tetris.cpp
	$(CC) $(FLAGS) $(LOC)Tetris.cpp -std=c++11 -o obj/Tetris.o

obj/Arkanoid.o: $(LOC)Arkanoid.cpp
	$(CC) $(FLAGS) $(LOC)Arkanoid.cpp -std=c++11 -o obj/Arkanoid.o

obj/Snake.o: $(LOC)Snake.cpp
	$(CC) $(FLAGS) $(LOC)Snake.cpp -std=c++11 -o obj/Snake.o


# clean up
clean:
	rm -f $(OBJS) $(OUT)
	rm -rf Docs
	rm -rf $(ODIR)
