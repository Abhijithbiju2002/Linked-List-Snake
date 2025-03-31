#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <random>

namespace Food {
	using namespace std;
	using namespace sf;

	enum class FoodType;
	class FoodItem;

	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		default_random_engine random_engine;
		random_device random_device;
		


		FoodItem* createFood(Vector2i position, FoodType type);
		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		sf::Vector2i getValidSpawnPosition();

		
		void spawnFood();

		void destroyFood();
		void reset();

	public:
		FoodService();
		~FoodService();

		Vector2i getRandomPosition();

		FoodType getRandomFoodType();
		void startFoodSpawning();

		void initialize();
		void update();
		void render();
		

	};
}


