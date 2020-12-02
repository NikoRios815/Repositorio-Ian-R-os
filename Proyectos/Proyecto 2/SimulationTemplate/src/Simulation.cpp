#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"


GameObject* pin;
GameObject* bg;
GameObject* gohan;
GameObject* videl;
GameObject* goten;
GameObject* satan;
GameObject* one;
GameObject* two;
GameObject* three;
GameObject* four;
GameObject* five;
GameObject* six;

Simulation::Simulation()
{}

Simulation::~Simulation()
{}

void Simulation::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized!" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		std::cout << "Couldn't initiate SDL..." << std::endl;
		isRunning = false;
	}

	pin = new GameObject("assets/box1.png", renderer);
	bg = new GameObject("assets/bg.png", renderer);
	gohan = new GameObject("assets/gohan.png", renderer);
	videl = new GameObject("assets/videl.png", renderer);
	goten = new GameObject("assets/goten.png", renderer);
	satan = new GameObject("assets/satan.png", renderer);
	one = new GameObject("assets/1.png", renderer);
	two = new GameObject("assets/2.png", renderer);
	three = new GameObject("assets/3.png", renderer);
	four = new GameObject("assets/4.png", renderer);
	five = new GameObject("assets/5.png", renderer);
	six = new GameObject("assets/6.png", renderer);
}

void Simulation::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Simulation::update(float dt)
{
	timeCount += dt;
	timeCountvidel += dt;
	timeCountgoten += dt;

	bg->update(0, 0, 1280, 800);

	//variables del pendulo
	t = 0.785398 * cos(0.7746 * timeCount);
	x = 1075 + 250 * sin(0.5 * cos(0.7746 * timeCount));
	y = 250 + 250 * cos(0.5 * cos(0.7746 * timeCount));

	//variables de los wave beam
	x_videl = 0 + 300 * timeCountvidel - 32;
	x_goten = 0 + 500 * timeCountgoten - 32;

	//Pendulo:
	satan->update(x - 50, y - 32, 98, 114);
	
	//Movimiento circular
	one->update(640 + 250 * cos(2 * timeCount) - 32, 400 + 250 * sin(2 * timeCount) - 32, 64, 64);
	two->update(640 + 150 * cos(3 * timeCount) - 32, 400 + 150 * sin(3 * timeCount) - 32, 64, 64);
	three->update(640 + 350 * cos(4 * timeCount) - 32, 400 + 350 * sin(4 * timeCount) - 32, 64, 64);

	//Movimiento oscilatorio horizontal
	four->update(190 + 150 * cos(2 * timeCount) - 32, 200, 64, 64);
	five->update(190 + 150 * cos(3 * timeCount) - 32, 400, 64, 64);
	six->update(190 + 150 * cos(4 * timeCount) - 32, 600, 64, 64);
	
	//Wavebeam:
	videl->update(x_videl, 384 + 10 * sin(10 * timeCount) - 32, 100, 82);
	goten->update(x_goten, 384 + 100 * sin(10 * timeCount) - 32, 100, 82);

	if (x_videl > 1280) {
		timeCountvidel = 0;
	}

	if (x_goten > 1280) {
		timeCountgoten = 0;
	}

	//movimiento oscilatorio vertical
	gohan->update(640 - (108 / 2), 384 + 10 * sin(5 * timeCount) - (183 / 2), 108, 183);

	pin->update(1075 - 8, 250 - 8, 16, 16);
}

void Simulation::render()
{
	SDL_RenderClear(renderer);

	bg->render();

	//Línea del péndulo
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	//La X y Y son las coordenadas de mrsatan para simular como si la línea estuviera amarrada a él
	SDL_RenderDrawLine(renderer, 1075, 250, x, y);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	
	pin->render();
	satan->render();
	videl->render();
	goten->render();
	one->render();
	two->render();
	three->render();
	four->render();
	five->render();
	six->render();
	gohan->render();



	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}
