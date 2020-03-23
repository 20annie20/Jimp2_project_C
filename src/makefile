game: test_game.o generacje.o loadfile.o 	
	$(CC) -o game test_game.o generacje.o loadfile.o

game_png: test_game.o generacje.o loadfile.o write_png.o names.o
	$(CC) -o game_png test_game.o generacje.o loadfile.o write_png.o names.o -lpng

test_game.o: test_game.c generacje.h
	$(CC) -c test_game.c generacje.h

generacje.o: generacje.c generacje.h loadfile.h names.h 
	$(CC) -c generacje.c generacje.h 

names.o: names.h names.c
	$(CC) -c names.c names.h

loadfile.o: loadfile.h loadfile.c
	$(CC) -c loadfile.h loadfile.c

write_png.o: write_png.h write_png.c loadfile.h
	$(CC) -c write_png.h write_png.c -lpng -g

.PHONY: clean

clean:
	-rm *.o *.gch 
