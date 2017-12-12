MACHINE= $(shell uname -s)

OBJDIR = bin
MAIN = bin/app

SRC = $(shell find . -name "*.cpp")
CXX = g++
CFLAGS = -g -Wall -O2 -std=c++0x

OPTIONS = ${CFLAGS}

ifeq ($(MACHINE),Darwin)
	LIBS = -F /Library/Frameworks -framework SDL2
	LIBS += -framework SDL2_image
else
	LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
endif

all: 
	@mkdir -p $(OBJDIR)
	${CXX} ${OPTIONS} ${SRC} -o ${MAIN} ${LIBS}

clean:
	rm -rf ${MAIN}

