PREFIX=/usr/local
BINDIR=${PREFIX}/bin

all: line

% : %.c
	gcc -std=c99 -o $@ $<

install: all
	install -m 755 -d ${BINDIR} line
