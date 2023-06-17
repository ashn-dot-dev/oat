.POSIX:
.SUFFIXES:
.PHONY: \
	all \
	examples \
	install \
	install-sunder \
	uninstall \
	uninstall-sunder \
	format \
	clean

PREFIX = /usr/local

EMCC = emcc
EMCFLAGS = \
	$(CFLAGS) \
	-sASSERTIONS -sASYNCIFY -sSINGLE_FILE=1 \
	-sUSE_SDL=2 -sUSE_SDL_IMAGE=2 -sUSE_SDL_MIXER=2 -sUSE_SDL_TTF=2 \
	-sSDL2_IMAGE_FORMATS='["png"]' \
	--shell-file emscripten-shell.html

all: liboat.a

examples: examples/demo examples/demo.html

liboat.a: oat.o
	$(AR) rcs $@ $<

oat.sunder: oat.h
	python3 bindings/sunder.py oat.h >$@

examples/demo: examples/demo.c liboat.a
	$(CC) -o $@ -I. $(CFLAGS) $$(sdl2-config --cflags) $^ -lm $$(sdl2-config --libs) -lSDL2_image -lSDL2_mixer -lSDL2_ttf

examples/demo.html: examples/demo.c oat.c
	$(EMCC) -o $@ -I. $(EMCFLAGS) $^

templates/c99/game: templates/c99/main.c
	cd templates/c99 && $(MAKE) build

templates/sunder/game: templates/sunder/main.sunder
	cd templates/sunder && $(MAKE) build

templates/sunder/game.html: templates/sunder/main.sunder
	cd templates/sunder && $(MAKE) build-web

install: liboat.a
	install -d $(DESTDIR)$(PREFIX)/include
	install -d $(DESTDIR)$(PREFIX)/lib
	install -m 644 oat.h $(DESTDIR)$(PREFIX)/include
	install -m 644 liboat.a $(DESTDIR)$(PREFIX)/lib
	install -m 755 oat-config $(DESTDIR)$(PREFIX)/bin

install-sunder: oat.sunder
	mkdir -p "$(SUNDER_HOME)/lib/oat"
	cp oat.h "$(SUNDER_HOME)/lib/oat"
	cp oat.c "$(SUNDER_HOME)/lib/oat"
	cp oat.sunder "$(SUNDER_HOME)/lib/oat"
	cp emscripten-shell.html "$(SUNDER_HOME)/lib/oat"

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/include/oat.h
	rm -f $(DESTDIR)$(PREFIX)/lib/liboat.a
	rm -f $(DESTDIR)$(PREFIX)/bin/oat-config

uninstall-sunder:
	rm -rf "$(SUNDER_HOME)/lib/oat"

format:
	clang-format -i *.c examples/*.c templates/c99/*.c

clean:
	rm -f oat.sunder
	rm -f examples/demo
	rm -f examples/demo.html
	rm -f templates/c99/game
	rm -f templates/sunder/game
	rm -f templates/sunder/game.html
	rm -f $$(find . -type f -name '*.a')
	rm -f $$(find . -type f -name '*.o')
	rm -f $$(find . -type f -name '*.js')
	rm -f $$(find . -type f -name '*.wasm')

.SUFFIXES: .c .o
.c.o:
	$(CC) -o $@ -c -I. $(CFLAGS) $<
