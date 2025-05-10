#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/RectangleShapeView.h"

namespace Level{
	using namespace UI::UIElement;
	using namespace sf;

	class LevelView
	{
	private:
		const Color background_color = sf::Color(180, 200, 160);
		const Color border_color = Color::Black;

		RectangleShapeView* background_rectangle;
		RectangleShapeView* border_rectangle;

		float grid_width;
		float grid_height;

		void createViews();
		
		
		void destroy();

	public:
		static const int border_thickness = 10;
		static const int border_offset_left = 40;
		static const int border_offset_top = 40;

		LevelView();
		~LevelView();

		void initialize();  // Lifecycle method
		void update();      // Lifecycle method
		void render();  
		// Lifecycle method
		void calculateGridExtents();
		void initializeBackground();
		void initializeBorder();
		float getGridWidth();
		float getGridHeight();

	};
}
	


