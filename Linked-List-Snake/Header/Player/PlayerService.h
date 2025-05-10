#pragma once
#include "../../Header/Player/SnakeController.h"

namespace Player {


	class PlayerService
	{
	private:
		
		SnakeController* snake_controller;

		void createController();
		void destroy();
		TimeComplexity time_complexity = TimeComplexity::NONE;
		LinkedListOperations last_operation = LinkedListOperations::NONE;

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		void spawnPlayer();
		int getPlayerScore();

		
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
	};
}


