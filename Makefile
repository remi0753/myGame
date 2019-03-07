main: main.c game.o display.o font.o
	gcc main.c game.o display.o font.o -o main -lglut -lGLU -lGL

game.o: game.c game.h define.h display.h
	gcc -c game.c -o game.o -lglut -lGLU -lGL

display.o: display.c display.h 
	gcc -c display.c -o display.o -lglut -lGLU -lGL

font.o: font.c font.h
	gcc -c font.c -o font.o -lglut -lGLU -lGL

clean:
	rm -rf main *.o
