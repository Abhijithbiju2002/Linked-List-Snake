#include "../../Header/Player/BodyPart.h"
#include"../../Header/Global/Config.h"
#include"../../Header/Level/LevelView.h"
#include"../../Header/Level/LevelModel.h"
#include <iostream>

using namespace Global;
using namespace Level;
using namespace sf;

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
		/*std::cout << "Snake texture path. " << Config::snake_body_texture_path.toAnsiString() << std::endl;
		std::cout << "get body part height " << bodypart_height << std::endl;
		std::cout << "get body part widh " << bodypart_width << std::endl;
		std::cout << "get body part screen x position " << getBodyPartScreenPosition().x<<
			"get y position " << getBodyPartScreenPosition().y << std::endl;*/

		bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
		
		bodypart_image->setOriginAtCentre();
	}
	Vector2f BodyPart::getBodyPartScreenPosition()
	{
		float x_screen_position = LevelView::border_offset_left + (grid_position.x *
			bodypart_width) + (bodypart_width / 2);
		float y_screen_position = LevelView::border_offset_top + (grid_position.y *
			bodypart_height) + (bodypart_height / 2);

		return Vector2f(x_screen_position, y_screen_position);
	}
	float BodyPart::getRotationAngle() {

		switch (direction) {
		case Direction::UP:
			return 270.f;
		case Direction::DOWN:
			return 90.f;
		case Direction::RIGHT:
			return 0;
		case Direction::LEFT:
			return 180.f;
		}
	}
	
	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView;
	}
	void BodyPart::setDirection(Direction direction) {

		previous_direction = this->direction;
		this->direction = direction;
	}
	void BodyPart::updatePosition() {
		grid_position = getNextPosition();

		bodypart_image->setPosition(getBodyPartScreenPosition());
		bodypart_image->setRotation(getRotationAngle());
		bodypart_image->update();
	}
	Vector2i BodyPart::getNextPosition() {

		switch (direction) {
		case Direction::UP:
			return getNextPositionUp();
		case Direction::DOWN:
			return getNextPositionDown();
		case Direction::RIGHT:
			return getNextPositionRight();
		case Direction::LEFT:
			return getNextPositionLeft();
		default:
			return grid_position;
		}
	}
	Vector2i BodyPart::getNextPositionDown() {

		return Vector2i(grid_position.x, (grid_position.y + 1)%(LevelModel::number_of_rows));
	}
	Vector2i BodyPart::getNextPositionUp() {

		return Vector2i(grid_position.x, (grid_position.y - 1 + LevelModel::number_of_rows)%
			(LevelModel::number_of_rows));
	}
	Vector2i BodyPart::getNextPositionRight() {

		return Vector2i((grid_position.x + 1)%(LevelModel::number_of_columns), grid_position.y);
	}
	Vector2i BodyPart::getNextPositionLeft() {

		return Vector2i((grid_position.x - 1 + LevelModel::number_of_columns)%
			(LevelModel::number_of_columns), grid_position.y);
	}
	void BodyPart::setPosition(sf::Vector2i position)
	{
		grid_position = position;
	}
	Vector2i BodyPart::getPrevPosition() {

		switch (direction) {
		case Direction::UP:
			return getNextPositionDown();
		case Direction::DOWN:
			return getNextPositionUp();
		case Direction::RIGHT:
			return getNextPositionLeft();
		case Direction::LEFT:
			return getNextPositionRight();
		default:
			return grid_position;
		}
	}
	void BodyPart::update()
	{
	}

	void BodyPart::render()
	{
		if (bodypart_image == nullptr) {
			std::cerr << "Error: head_node is null in render()" << std::endl;
			return;
		}
		bodypart_image->render();
	}

	void BodyPart::destroy()
	{
		delete bodypart_image;
	}
	Direction BodyPart::getPreviousDirection()
	{
		return previous_direction;
	}
	Direction BodyPart::getDirection() {

		return direction;
	}
	Vector2i BodyPart::getPosition() {

		return grid_position;
	}

}
