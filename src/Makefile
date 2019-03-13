PROGRAM = main
OBJS = \
game.o \
font.o \
key.o \
sceneManager.o \
shape/rect.o \
shape/ball.o \
scene/menu/sceneMenu.o \
scene/game/sceneGame.o \
scene/game/sceneGameBoard.o \
fps.o \
player.o

CC = gcc
CFLAGS = -lglut -lGLU -lGL -lm

.SUFFIXES: .c .o

$(PROGRAM): $(OBJS)
	$(CC) $(PROGRAM).c $^ -o $(PROGRAM) $(CFLAGS)

.c.o:
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(OBJS)

game.o: game.h
key.o: key.h
font.o: font.h
sceneManager.o: sceneManager.h
sceneMenu.o: sceneMenu.h
sceneGame.o: sceneMenu.h
sceneGameBoard.o: sceneGameBoard.h
fps.o: fps.h
rect.o: rect.h
ball.o: ball.h
player.o: player.h
