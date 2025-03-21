#pragma once
#include "Level/LevelService.h"

namespace Level {
	class LevelService;

	class LevelController
	{
	private:
		LevelService* level_service;

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();


	};

}