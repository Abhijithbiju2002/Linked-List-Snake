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
	enum InputState
	{
		WAITING,
		PROCESSING
	};
	class SnakeController
	{
	private:
		const int initial_snake_lengeth = 10;

		const int restart_duration = 0.f;
		
		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;

		const float movement_frame_duration = 0.1f;
		float restart_counter;
		float elapsed_duration = 0.f;

		SnakeState current_snake_state;
		Direction current_snake_direction;
		InputState current_input_state;

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
		void delayedUpdate();
		void spawnSnake();
		void respawnSnake();
		
		
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
		
	};

}

