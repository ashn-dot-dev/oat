.POSIX:
.SUFFIXES:
.PHONY: \
	all \
	build \
	build-web \
	clean

TARGET=game

EMCC = emcc
EMCFLAGS = \
	$(CFLAGS) \
	-I$(SUNDER_HOME)/lib/oat \
	-sASSERTIONS -sASYNCIFY -sSINGLE_FILE=1 \
	-sUSE_SDL=2 -sUSE_SDL_IMAGE=2 -sUSE_SDL_MIXER=2 -sUSE_SDL_TTF=2 \
	-sSDL2_IMAGE_FORMATS=[png] \
	--shell-file $(SUNDER_HOME)/lib/oat/emscripten-shell.html

all: build build-web

build:
	SUNDER_CFLAGS="$$(oat-config --cflags)" \
	sunder-compile -o $(TARGET) $$(oat-config --libs) main.sunder

build-web:
	SUNDER_ARCH=wasm32 \
	SUNDER_HOST=emscripten \
	SUNDER_CC=$(EMCC) \
	SUNDER_CFLAGS="$(EMCFLAGS)" \
	sunder-compile -o $(TARGET).html main.sunder $(SUNDER_HOME)/lib/oat/oat.c

clean:
	rm -f $(TARGET) $(TARGET).html *.wasm *.o *.c
