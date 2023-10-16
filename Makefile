build:
	g++ -Wall -std=c++17 -I"./libs/" src/*.cpp src/*/*.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.4  -o biscotti_engine; 

run:
	./biscotti_engine
clean:
	rm biscotti_engine
