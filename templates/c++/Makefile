.POSIX:
.SUFFIXES:
.PHONY: \
	all \
	build \
	clean

TARGET=game

all: build

build: main.o
	$(CXX) -o $(TARGET) $(CXXFLAGS) $$(oat-config --cxxflags) $^ $$(oat-config --libs)

clean:
	rm -f $(TARGET) *.o

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) -o $@ -c -I. $(CXXFLAGS) $<
