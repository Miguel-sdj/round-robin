cc = G++

all: robin

robin: main.cpp
	g++ -o robin main.cpp

.PHONY: clean run

run:
	./robin

clean:
	rm -rf robin