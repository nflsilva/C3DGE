
#include "tools/Log.hpp"
#include "core/CoreEngine.hpp"
#include "Game.hpp"

int main(int argc, char **argv){

	CoreEngine e;
	Game g(&e);
	e.SetDelegate(&g);
	e.Start();

	Log::D("Done!");
	return 0;
}
