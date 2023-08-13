#include <iostream>
#include <raylib.h>
#include <Event.hpp>

using namespace std;

int main() {
	InitWindow(800, 600, "A");

	//avc();
	auto e = Event<int, int>();
	e.invoke(1);
	testfunc();
	CloseWindow();
	return 0;
}
