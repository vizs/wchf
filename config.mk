__NAME__ = wchf
__NAME_CLIENT__ = waitron
__CONFIG_NAME__ = wchfrc
VERCMD ?= git describe 2> /dev/null
__THIS_VERSION__ = $(shell $(VERCMD) || cat VERSION)

PREFIX    = $(HOME)/usr/local
MANPREFIX = $(PREFIX)/share/man
MANDIR    = $(MANPREFIX)/man1
DOCPREFIX = $(PREFIX)/share/doc

CFLAGS += -std=c99 -Wall -Wextra -O2
LDFLAGS += -lm -lxcb -lxcb-ewmh -lxcb-icccm -lxcb-randr -lxcb-keysyms
