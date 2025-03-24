#include "../../Header/Player/SnakeController.h"
#include "../../Header/Global/ServiceLocator.h"
//#include "../../include/LinkedList/SingleLinkedList.h"

namespace Player {
	using namespace LinkedList;
	using namespace Global;

	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;
		createLinkedList();
	}

    SnakeController::~SnakeController()
	{
		destroy();
	}
	void SnakeController::createLinkedList()
	{
		single_linked_list = new LinkedList::SingleLinkedList();
	}

	void SnakeController::initialize()
	{

		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		
		single_linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::update()
	{
		switch (current_snake_state) {

		case SnakeState::ALIVE:
			processPlayerInput();
			updateSnakeDirection();
			processSnakeCollision();
			moveSnake();
			break;

		case SnakeState::DEAD:
			handleRestart();

		}
	}

	void SnakeController::render()
	{

	}
	void SnakeController::processPlayerInput() {

	}
	void SnakeController::updateSnakeDirection() {

	}
	void SnakeController::moveSnake() {

	}
	void SnakeController::processSnakeCollision() {

	}
	void SnakeController::handleRestart() {

	}
	void SnakeController::spawnSnake() {
		single_linked_list->createHeadNote();
	}
	void SnakeController::reset() {

	}
	void SnakeController::respawnSnake(){

	}
	void SnakeController::setSnakeState(SnakeState state) {
		current_snake_state = state;
	}
	SnakeState SnakeController::getSnakeState() {
		return current_snake_state;
	}
	void SnakeController::destroy() {

	}


}
