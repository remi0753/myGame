# Makefile_other

# プログラム名とオブジェクトファイル名
PROGRAM = main
OBJS = \
game.o \
font.o \
key.o \
scene.o \
sceneMenu.o \
sceneGame.o

# 定義済みマクロの再定義
CC = gcc
CFLAGS = -lglut -lGLU -lGL

# サフィックスルール適用対象の拡張子の定義
.SUFFIXES: .c .o

# プライマリターゲット
$(PROGRAM): $(OBJS)
	$(CC) $(PROGRAM).c -o $(PROGRAM) $^ $(CFLAGS)

# サフィックスルール
.c.o:
	$(CC) -c $< $(CFLAGS)

# ファイル削除用ターゲット
.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(OBJS)

# ヘッダファイルの依存関係
main.o: game.h
game.o: define.h game.h key.h scene.h sceneMenu.h sceneGame.h
key.o: key.h
font.o: font.h
scene.o: scene.h
sceneMenu.o: sceneMenu.h
sceneGame.o: sceneMenu.h
