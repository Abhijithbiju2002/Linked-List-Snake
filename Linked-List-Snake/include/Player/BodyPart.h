#pragma once
#include "Player/Direction.h"
#include <SFML/System/Vector2.hpp>
#include"UI/UIElement/ImageView.h"


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
		void updatePosition();
		void update();
		void render();
		void destroy();

		
	};
}
