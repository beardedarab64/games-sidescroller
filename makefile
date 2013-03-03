all: 
	g++ -o main main.cpp sprite.cpp -lsfml-graphics -lGL -lsfml-system -lsfml-window -std=c++0x && ./main
