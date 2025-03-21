#include "Level/LevelView.h"
#include "Global/ServiceLocator.h"
#include "Graphics/GraphicService.h"
#include "UI/UIElement/RectangleShapeView.h"

namespace Level {
	
	using namespace UI::UIElement;
	using namespace Global;

	LevelView::LevelView() {

		createViews();
	}
	LevelView::~LevelView() {

		destroy();
	}
	void LevelView::initialize() {

		initializeBackground();
		calculateGridExtents();
		initializeBorder();
	}
	void LevelView::initializeBackground() {

		RenderWindow* game_window = ServiceLocator::getInstance()
			->getGraphicService()->getGameWindow();
		Vector2f background_size = Vector2f(game_window->getSize().x,
			game_window->getSize().y);

		background_rectangle->initialize(background_size, Vector2f(0, 0), 0,
			background_color);
		background_rectangle->show();
	}
	void LevelView::initializeBorder() {

		RenderWindow* game_window = ServiceLocator::getInstance()
			->getGraphicService()->getGameWindow();

		Vector2f border_size = Vector2f(grid_width, grid_height);
		Vector2f border_position = Vector2f(border_offset_left, border_offset_top);

		border_rectangle->initialize(border_size, border_position, border_thickness,
			Color::Transparent, border_color);
		border_rectangle->show();
	}
	void LevelView::calculateGridExtents() {
		RenderWindow* game_window = ServiceLocator::getInstance()
			->getGraphicService()->getGameWindow();

		grid_width = game_window->getSize().x - 2 * border_offset_left;
		grid_height = game_window->getSize().y - 2 * border_offset_top;
	}

	void LevelView::destroy() {

		delete(background_rectangle);
		delete(border_rectangle);
	}

	void LevelView::update() {
		background_rectangle->update();
		border_rectangle->update();

	}
	void LevelView::createViews() {

	}
	void LevelView::render() {

		background_rectangle->render();
		border_rectangle->render();
	}
	float LevelView::getGridWidth() {
		return grid_width;

	}
	float LevelView::getGridHeight() {
		return grid_height;
	}
}
