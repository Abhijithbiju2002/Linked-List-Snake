#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <random>
#include "../../Header/LinkedListLib/SingleLinked/SingleLinkedList.h"

namespace Food {
	using namespace std;
	using namespace sf;

	enum class FoodType;
	class FoodItem;

	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};
	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		default_random_engine random_engine;
		random_device random_device;
		
		const float spawn_duration = 4.f;
		float elapsed_duration;

		FoodSpawningStatus current_spawning_status;

		FoodItem* createFood(Vector2i position, FoodType type);
		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		sf::Vector2i getValidSpawnPosition();

		
		void spawnFood();

		
		void reset();

	public:
		FoodService();
		~FoodService();

		Vector2i getRandomPosition();

		FoodType getRandomFoodType();
		void startFoodSpawning();

		void updateElapsedDuration();

		void handleFoodSpawning();

		
		bool processFoodCollision(LinkedListLib::Node* head_node, FoodType& out_food_type);

		void destroyFood();

		void stopFoodSpawning();

		void initialize();
		void update();
		void render();
		

	};
}


