#pragma once
#include <SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"
#include"../../Header/Food/FoodType.h"

namespace Food {
	using namespace sf;

	class FoodItem
	{
	private:
		UI::UIElement::ImageView* food_image;

			Vector2i grid_position;

			float cell_width;
			float cell_height;

			FoodType food_type;

			void initializeFoodImage();
			String getFoodTexturePath();

			Vector2f getFoodImagePosition();

	public:
		static const int number_of_foods = 8;

		FoodItem();
		~FoodItem();

		void initialize(sf::Vector2i grid_pos, float width, float height, FoodType type);

		void update();
		void render();
		
		FoodType getFoodType();
		
	};

}


