#include "../../Header/Level/LevelService.h"
#include "../../Header/Level/LevelController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Element/ElementService.h"


namespace Level {

	using namespace Element;
	using namespace Global;
	

	LevelService::LevelService() {
		level_controller = nullptr;

		createLevelController();
	}

	LevelService::~LevelService()
	{
		destroy();
	}

	void LevelService::createLevelController()
	{
		level_controller = new LevelController();
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	float LevelService::getCellWidth()
	{
		return level_controller->getCellWidth();
	}

	float LevelService::getCellHeight()
	{
		return level_controller->getCellHeight();
	}

	void LevelService::spawnFood()
	{
		ServiceLocator::getInstance()->getFoodService()->startFoodSpawning();
	}

	void LevelService::createLevel(LinkedListType linked_list_type)
	{
		current_linked_list_type = linked_list_type;
		spawnLevelElements(current_level);
		spawnFood();
		spawnPlayer();
	}
	void LevelService::spawnLevelElements(LevelNumber level_to_load) {

		float cell_width = level_controller->getCellWidth();
		float cell_height = level_controller->getCellHeight();

			std::vector<ElementData> element_data_list = level_controller->getElementDataList((int)level_to_load);
	        ServiceLocator::getInstance()->getElementService()->spawnElements(element_data_list, cell_width, cell_height);
	}
	void LevelService::setCurrentLevelNumber(LevelNumber level_to_load) {
		current_level = level_to_load;
	}
	LevelNumber LevelService::getCurrentLevel()
	{
		return current_level;
	}
	void LevelService::spawnPlayer()
	{
		ServiceLocator::getInstance()->getPlayerService()->spawnPlayer(current_linked_list_type);
	}
	void LevelService::destroy()
	{
		delete level_controller;
	}
	


}
