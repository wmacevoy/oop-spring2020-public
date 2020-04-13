TARGET=calc
CXXFLAGS = -std=c++0x -g -Iinclude -fPIC
GXXFLAGS = -Iinclude

TESTS=$(wildcard tests/*.wmpp)
OUTPUT=$(patsubst %.wmpp,%.out,$(TESTS))

all : dirs bin/compile $(OUTPUT)

dirs :
	mkdir -p tmp bin lib

%.j : %.wmpp bin/compile
	./context bin/compile $<

%.class : %.j
	java -jar jasmin.jar $<

%.out : %.class
	java $* > $@

include rules.mk
