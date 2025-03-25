#pragma once
#include "../../Header/Player/Direction.h"
#include <SFML/System/Vector2.hpp>
#include"../../Header/UI/UIElement/ImageView.h"


namespace Player {

	using namespace sf;

	class BodyPart {
	
	protected:
		UI::UIElement::ImageView* bodypart_image;

		Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;

		void createBodyPartImage();

		

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width,float height,Vector2i pos,Direction dir);
		void initializeBodyPartImage();
		Vector2f getBodyPartScreenPosition();
		float getRotationAngle();
		void setDirection(Direction direction);

		Vector2i getNextPosition();
		Vector2i getNextPositionDown();
		Vector2i getNextPositionUp();
		Vector2i getNextPositionRight();
		Vector2i getNextPositionLeft();

		void setPosition(sf::Vector2i position);

		void updatePosition();
		void update();
		void render();
		void destroy();

		Direction getDirection();

		Vector2i getPosition();

		
	};
}
