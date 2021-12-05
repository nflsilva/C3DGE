#include "core/CoreEngine.hpp"

#include "App.hpp"
#include "Game.hpp"

int main(int argc, char **argv){

	CoreEngine e;
	Game g(&e);
	e.SetDelegate(&g);
	e.Start();

	Log::I("Done!");
	return 0;
}