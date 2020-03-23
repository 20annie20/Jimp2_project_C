game: test_game.o generacje.o loadfile.o	
	$(CC) -o game test_game.o generacje.o loadfile.o

game_png: test_game.o generacje.o loadfile.o write_png.o
	$(CC) -o game_png test_game.o generacje.o loadfile.o write_png.o

test_game.o: test_game.c generacje.h
	$(CC) -c test_game.c generacje.h

generacje.o: generacje.c generacje.h loadfile.h 
	$(CC) -c generacje.c generacje.h 

loadfile.o: loadfile.h loadfile.c
	$(CC) -c loadfile.h loadfile.c

write_png.o: write_png.h write_png.c loadfile.h
	$(CC) -c write_png.h write_png.c

.PHONY: clean

clean:
	-rm *.o game game_png
