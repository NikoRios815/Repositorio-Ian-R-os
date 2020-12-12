#include "nemBody.h"
#include "nemWorld.h"
#include <iostream>

int main() {
	//We declare the body in this case a box.
	nBody Box;
	Box.displayBodyInfo();
	//We declare the world and add the desire gravity.
	nemWorld mainWorld(vec2D(0.0f, 9.81f));
	//We add the body to the world.
	mainWorld.addBody(&Box);
	
	//we decide on the frametime and the duration of the simulation.
	float frameTime = 0.16f;
	int simDuration = 60;

	//we loop the sim results to be able to see them.
	for(int i = 0; i < simDuration; i++){
		mainWorld.Step(frameTime);
		Box.displayBodyInfo();
	}
	return 0;
}
