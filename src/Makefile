main: main.c game.o sceneMenu.o sceneGame.o font.o scene.o
	gcc main.c game.o sceneMenu.o sceneGame.o font.o scene.o -o main -lglut -lGLU -lGL

game.o: game.c game.h
	gcc -c game.c -o game.o -lglut -lGLU -lGL

font.o: font.c font.h
	gcc -c font.c -o font.o -lglut -lGLU -lGL

scene.o: scene.c scene.h
	gcc -c scene.c -o scene.o -lglut -lGLU -lGL

sceneMenu.o: sceneMenu.c sceneMenu.h 
	gcc -c sceneMenu.c -o sceneMenu.o -lglut -lGLU -lGL

sceneGame.o: sceneGame.c sceneGame.h 
	gcc -c sceneGame.c -o sceneGame.o -lglut -lGLU -lGL

clean:
	rm -rf main *.o
