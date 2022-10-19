all: test speed
test:
	gcc aes.c gmult.c test.c -O3 -o test
speed:
	gcc aes.c gmult.c speed.c -O3 -o speed
clean:
	rm ./speed ./test
