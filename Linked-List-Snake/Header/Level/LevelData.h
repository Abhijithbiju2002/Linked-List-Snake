#pragma once
#include "../../Header/Level/LevelService.h"
#include "../../Header/Level/LevelNumber.h"

namespace Level {

	struct LevelData {
		
		LevelData(LevelNumber ind)
		{
			level_index = ind;
		}

		LevelNumber level_index;
	};
}