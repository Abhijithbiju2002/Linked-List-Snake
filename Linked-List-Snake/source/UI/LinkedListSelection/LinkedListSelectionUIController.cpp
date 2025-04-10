#include "../../Header/UI/LinkedListSelection/LinkedListSelectionUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/UI/UIElement/ButtonView.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/Global/Config.h"

namespace UI
{
	using namespace UIElement;
	using namespace Global;
	using namespace Event;
	using namespace Sound;
	using namespace Main;

	namespace LinkedListSelection {

		LinkedListSelectionUIController::LinkedListSelectionUIController()
		{
			createButtons();
			createImage();
		}

		LinkedListSelectionUIController::~LinkedListSelectionUIController()
		{
			destroy();
		}

		void LinkedListSelectionUIController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}

		void LinkedListSelectionUIController::createImage()
		{
			background_image = new ImageView();
		}

		void LinkedListSelectionUIController::createButtons()
		{
			single_link_button = new ButtonView();
			double_link_button = new ButtonView();
			menu_button = new ButtonView();
		}

		void LinkedListSelectionUIController::initializeBackgroundImage()
		{
			auto* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}

		void LinkedListSelectionUIController::initializeButtons()
		{
			float x = calculateLeftOffset();

			single_link_button->initialize("Single Linked List",
				Config::single_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x, single_button_y));

			double_link_button->initialize("Doubly Linked List",
				Config::single_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x, double_button_y));

			menu_button->initialize("Main Menu",
				Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(x, menu_button_y));
		}

		void LinkedListSelectionUIController::registerButtonCallback()
		{
			single_link_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::singleLinkCallback, this));
			double_link_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::doubleLinkCallback, this));
			menu_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::menuCallback, this));
		}

		float LinkedListSelectionUIController::calculateLeftOffset()
		{
			auto* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			return (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
		}

		void LinkedListSelectionUIController::singleLinkCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LinkedListType::SINGLE_LINKED_LIST);
		}

		void LinkedListSelectionUIController::doubleLinkCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LinkedListType::DOUBLE_LINKED_LIST);
		}

		void LinkedListSelectionUIController::menuCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::MAIN_MENU);
		}

		void LinkedListSelectionUIController::update()
		{
			background_image->update();
			single_link_button->update();
			double_link_button->update();
			menu_button->update();
		}

		void LinkedListSelectionUIController::render()
		{
			background_image->render();
			single_link_button->render();
			double_link_button->render();
			menu_button->render();
		}

		void LinkedListSelectionUIController::show()
		{
			background_image->show();
			single_link_button->show();
			double_link_button->show();
			menu_button->show();
		}

		void LinkedListSelectionUIController::destroy()
		{
			delete background_image;
			delete single_link_button;
			delete double_link_button;
			delete menu_button;
		}
	}
}