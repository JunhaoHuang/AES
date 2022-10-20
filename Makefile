CFLAGS+=-O0
all: test speed
test:
	mkdir -p bin
	gcc aes.c test.c $(CFLAGS) -o bin/test
speed:
	mkdir -p bin
	gcc aes.c speed.c $(CFLAGS) -o bin/speed
clean:
	rm -rf bin/
