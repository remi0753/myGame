PROGRAM = main
OBJS = \
game.o \
font.o \
key.o \
scene.o \
sceneMenu.o \
sceneGame.o

CC = gcc
CFLAGS = -lglut -lGLU -lGL

.SUFFIXES: .c .o

$(PROGRAM): $(OBJS)
	$(CC) $(PROGRAM).c -o $(PROGRAM) $^ $(CFLAGS)

.c.o:
	$(CC) -c $< $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(OBJS)

game.o: game.h
key.o: key.h
font.o: font.h
scene.o: scene.h
sceneMenu.o: sceneMenu.h
sceneGame.o: sceneMenu.h
