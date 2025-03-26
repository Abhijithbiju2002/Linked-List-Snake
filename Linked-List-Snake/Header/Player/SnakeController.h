#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../Header/Player/Direction.h"
#include "../../Header/LinkedList/SingleLinkedList.h"

namespace Player {
	
	using namespace LinkedList;
	
	enum SnakeState {
		ALIVE,
		DEAD,
	};
	class SnakeController
	{
	private:
		const int initial_snake_lengeth = 10;
		
		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;

		const float movement_frame_duration = 0.1f;

		SnakeState current_snake_state;
		Direction current_snake_direction;

		SingleLinkedList* single_linked_list;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void destroy();

		void createLinkedList();
		

	public:
		SnakeController();
		~SnakeController();

		void initialize();     
		void update();   
		void render();   
		//void delayedUpdate();
		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
		
	};

}

