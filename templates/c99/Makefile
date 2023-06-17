.POSIX:
.SUFFIXES:
.PHONY: \
	all \
	build \
	clean

TARGET=game

all: build

build: main.o
	$(CC) -o $(TARGET) $(CFLAGS) $$(oat-config --cflags) $^ -lm $$(oat-config --libs)

clean:
	rm -f $(TARGET) *.o

.SUFFIXES: .c .o
.c.o:
	$(CC) -o $@ -c -I. $(CFLAGS) $<
