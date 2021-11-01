
#include "tools/Log.hpp"
#include "Core.hpp"

int main(int argc, char **argv){

	Core* c = new Core();
	c->Start();

	Log::D("Done!");
	return 0;
}
