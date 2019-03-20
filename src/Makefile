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
player.o \
enemy/enemyManager.o \
enemy/enemyInfo.o \
enemy/enemyShare.o \
enemy/types/enemyType1.o \
enemy/types/enemyType2.o \
enemy/moves/enemyMove.o \
enemy/enemyShotManager.o

CC = gcc
CFLAGS = -lglut -lGLU -lGL -lm
OPTIMIZE = -O2

.SUFFIXES: .c .o

$(PROGRAM): $(OBJS)
	$(CC) $(OPTIMIZE) $(PROGRAM).c $^ -o $(PROGRAM) $(CFLAGS)

.c.o:
	$(CC) $(OPTIMIZE) -c $< $(CFLAGS) -o $@

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
enemyManager.o: enemyManager.h enemyInfo.h
enemyInfo.o: enemyInfo.h
enemyShare.o: enemyShare.h enemyInfo.h
enemyType1.o: enemyAppearance.h enemyInfo.h
enemyType2.o: enemyAppearance.h enemyInfo.h
enemyMove.o: enemyMove.h enemyInfo.h
enemyShotManager.o: enemyShotManager.h enemyInfo.h
