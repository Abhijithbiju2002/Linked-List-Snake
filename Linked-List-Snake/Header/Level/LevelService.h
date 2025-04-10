#pragma once
#include "../../Header/Level/LevelConfig.h"

namespace Level {

	class LevelController;

	class LevelService
	{

	private:
		LevelController* level_controller;
		LevelNumber current_level;

		LinkedListType current_linked_list_type;

		void createLevelController();
		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();

		void spawnFood();

		void createLevel(LinkedListType linked_list_type);
		void spawnLevelElements(LevelNumber level_to_load);
		void setCurrentLevelNumber(LevelNumber level_to_load);
		LevelNumber getCurrentLevel();
		void spawnPlayer();
	};

}

