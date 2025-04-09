#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../Header/Player/Direction.h"
#include "../../Header/LinkedListLib/SingleLinked/SingleLinkedList.h"
#include "../../Header/Food/FoodType.h"



namespace Player {
	
	using namespace LinkedListLib::SingleLinked;
	using namespace Food;
	
	enum SnakeState {
		ALIVE,
		DEAD,
	};
	enum InputState
	{
		WAITING,
		PROCESSING
	};
	enum class TimeComplexity {
		NONE,
		ONE,
		N,
	};
	enum class LinkedListOperations {
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};
	class SnakeController
	{
	private:
		int player_score;

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

		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;


		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();

		void OnFoodCollected(FoodType food_type);

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

		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		
		
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
		int getPlayerScore();
		
	};

}

