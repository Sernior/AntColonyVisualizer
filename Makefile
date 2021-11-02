all: compile link
compile:
	g++ -I src/include -O3 -c main.cpp
link:
	g++ AntSimulation.cpp main.cpp Dijkstra.cpp Gui.cpp TimeManager.cpp Menu.cpp Map.cpp Globals.cpp tile.cpp tile_view.cpp Renderable.cpp -o main.exe -L src/lib -l sfml-graphics -l sfml-window -l sfml-system