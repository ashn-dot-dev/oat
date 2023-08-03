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
	$$($(SUNDER_HOME)/lib/oat/oat-config --emcflags) \
	-I$(SUNDER_HOME)/lib/oat \
	-sSINGLE_FILE=1 \
	--shell-file $(SUNDER_HOME)/lib/oat/emscripten-shell.html

all: build build-web

build:
	SUNDER_CFLAGS="$(CFLAGS) $$(oat-config --cflags)" \
	sunder-compile -o $(TARGET) $$(oat-config --libs) main.sunder

build-web:
	SUNDER_ARCH=wasm32 \
	SUNDER_HOST=emscripten \
	SUNDER_CC=$(EMCC) \
	SUNDER_CFLAGS="$(EMCFLAGS)" \
	sunder-compile -o $(TARGET).html main.sunder $(SUNDER_HOME)/lib/oat/oat.c

clean:
	rm -f $(TARGET) $(TARGET).html *.wasm *.o *.c
