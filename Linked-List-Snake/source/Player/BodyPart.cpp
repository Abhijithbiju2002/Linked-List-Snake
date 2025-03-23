#include "Player/BodyPart.h"
#include"Global/Config.h"

using namespace Global;

namespace Player {

	BodyPart::BodyPart()
	{
		createBodyPartImage();
		grid_position = { 0,0 };
	}

	BodyPart::~BodyPart()
	{
	}
	void BodyPart::initialize(float width, float height, Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		direction = dir;
		grid_position = pos;

		initializeBodyPartImage();

	}
	void BodyPart::initializeBodyPartImage() {
		bodypart_image ->initialize(Config::snake_body_texture_path,bodypart_width,
	    bodypart_height, getBodyPartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}
	Vector2f BodyPart::getBodyPartScreenPosition()
	{
		return getBodyPartScreenPosition();
	}
	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new UI::UIElement::ImageView;
	}
	void BodyPart::update()
	{
	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}

	void BodyPart::destroy()
	{
		delete bodypart_image;
	}

}
