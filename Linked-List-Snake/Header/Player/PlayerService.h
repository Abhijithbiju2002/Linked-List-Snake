#pragma once
#include "../../Header/Player/SnakeController.h"

namespace Player {


	class PlayerService
	{
	private:
		
		SnakeController* snake_controller;

		void createController();
		void destroy();


	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		void spawnPlayer();
	};
}


