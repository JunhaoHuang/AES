CFLAGS+=-O0	$(FLAG1) $(FLAG2)
all: test speed
test:
	mkdir -p bin
	gcc aes.c gmult.c test.c $(CFLAGS) -o bin/test
speed:
	mkdir -p bin
	gcc aes.c gmult.c speed.c $(CFLAGS) -o bin/speed
clean:
	rm -rf bin/
