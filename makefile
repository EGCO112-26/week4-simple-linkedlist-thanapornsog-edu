compile: main.c main-exercise.c
	gcc main.c -o ming
	gcc main-exercise.c -o test

run: ming test
	./ming
	./test 6613266 Gatuex 6613269 Ozone

clean: 
	rm -f ming test
