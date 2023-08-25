cc=g++
cflags=-g -Wall -O2

srcfiles=$(wildcard source/*.cpp)

.PHONY: run

main.exe: $(patsubst source/%.cpp,obj/%.o,$(srcfiles))
	$(cc) $(cflags) -o $@ $^

obj/%.o: source/%.cpp
	$(cc) $(cflags) -c $^ -Iheaders -o $@

run: main.exe
	./main