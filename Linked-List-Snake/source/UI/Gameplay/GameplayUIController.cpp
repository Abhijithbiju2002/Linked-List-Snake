#include "../../Header/UI/Gameplay/GameplayUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Level/LevelModel.h"
#include "../../Header/Player/PlayerService.h"
#include <iostream>

namespace UI
{
    namespace GameplayUI
    {
        using namespace Global;
        using namespace Event;
        using namespace Sound;
        using namespace Main;
        using namespace Graphics;
        using namespace Level;
        using namespace Player;
        using namespace UI::UIElement;

        GameplayUIController::GameplayUIController()
        {
            createTexts();
        }

        GameplayUIController::~GameplayUIController()
        {
            destroy();
        }

        void GameplayUIController::initialize()
        {
            std::cout << "GameplayUIController initialized!" << std::endl;
            initializeTexts();
            //show();
            
        }

        void GameplayUIController::createTexts()
        {
            std::cout << "Creating texts..." << std::endl;
            level_number_text = new TextView();
            score_text = new TextView();
            time_complexity_text = new TextView();
            operation_text = new TextView();
        }

        void GameplayUIController::initializeTexts()
        {
            std::cout << "Initializing texts..." << std::endl;
            initializeLevelNumberText();
            initializeScoreText();
            initializeTimeComplexityText();
            initializeOperationText();
        }

        void GameplayUIController::initializeLevelNumberText()
        {
            std::cout << "Initializing Level Number Text..." << std::endl;
            level_number_text->initialize("Level : 1", sf::Vector2f(level_number_text_x_position, text_y_position),
            FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
        }

        void GameplayUIController::initializeScoreText()
        {
            std::cout << "Initializing Score Text..." << std::endl;
            score_text->initialize("Score : 0", sf::Vector2f(score_text_x_position, text_y_position),
            FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);

            // Debugging: Print to check if the text is being initialized
            std::cout << "Score text initialized" << std::endl;
        }

        //initialize text for time complexity display
        void GameplayUIController::initializeTimeComplexityText()
        {
            time_complexity_text->initialize("Time Complexity : O(1)", sf::Vector2f(time_complexity_text_x_position,
                time_complexity_text_y_position), FontType::BUBBLE_BOBBLE, operations_font_size, sf::Color::Black);
        }
        // Initialize text for operation display
        void GameplayUIController::initializeOperationText()
        {
            operation_text->initialize("Last Operation : Insert at Middle", sf::Vector2f(operations_text_x_position,
                operations_text_y_position), FontType::BUBBLE_BOBBLE, operations_font_size, sf::Color::Black);
        }
        // Update time complexity text based on current player 
        void GameplayUIController::updateTimeComplexityText()
        {
           // std::cout << "Updating Time Complexity Text..." << std::endl;
            // Get time complexity from player service
            TimeComplexity time_complexity = ServiceLocator::getInstance()->getPlayerService()->getTimeComplexity();
            sf::String time_complexity_value;

            // Convert complexity to string based on enum value
            switch (time_complexity) {
            case TimeComplexity::NONE:
                time_complexity_value = "";
               break;
            case TimeComplexity::ONE:
                time_complexity_value = "1";
                break;
            case TimeComplexity::N:
                time_complexity_value = "N";
                break;
            }
            // Update text with formatted time complexity
            time_complexity_text->setText("Time Complexity :(" + time_complexity_value + ")");
            time_complexity_text->update();
        }
        // Update operation text based on last linked list operation
        void GameplayUIController::updateOperationText()
        {
            //std::cout << "Updating last operatotr Text..." << std::endl;
            // Get last operation type from player service
            LinkedListOperations operation = ServiceLocator::getInstance()->getPlayerService()->getLastOperation();
            sf::String operation_value;

            // Convert operation type to string based on enum value
            switch (operation)
            {
            case LinkedListOperations::NONE:
                operation_value = "";
                break;
            case LinkedListOperations::INSERT_AT_HEAD:
                operation_value = "Insert at Head";
                break;
            case LinkedListOperations::INSERT_AT_TAIL:
                operation_value = "Insert at Tail";
                break;
            case LinkedListOperations::INSERT_AT_MID:
                operation_value = "Insert at Mid";
                break;
            case LinkedListOperations::REMOVE_AT_HEAD:
                operation_value = "Remove at Head";
                break;
            case LinkedListOperations::REMOVE_AT_TAIL:
                operation_value = "Remove at Tail";
                break;
            case LinkedListOperations::REMOVE_AT_MID:
                operation_value = "Remove at Mid";
                break;
            case LinkedListOperations::DELETE_HALF_LIST:
                operation_value = "Delete Half List";
                break;
            case LinkedListOperations::REVERSE_LIST:
                operation_value = "Reverse List";
                break;
            }
            // Update text with formatted operation information
            operation_text->setText("Last Operation :" + operation_value);
            operation_text->update();
        }

        void GameplayUIController::updateLevelNumberText()
        {
            LevelNumber level_number = ServiceLocator::getInstance()->getLevelService()->getCurrentLevel();
            sf::String level_number_value = std::to_string(1 + static_cast<int>(level_number));

            level_number_text->setText("Level : " + level_number_value);
            level_number_text->update();
        }

        void GameplayUIController::updateScoreText()
        {
            int player_score = ServiceLocator::getInstance()->getPlayerService()->getPlayerScore();
            sf::String score_value = std::to_string(player_score);

            score_text->setText("Score : " + score_value);
            score_text->update();
        }

        void GameplayUIController::update()
        {
            updateLevelNumberText();
            updateScoreText();
            updateTimeComplexityText();
            updateOperationText();

        }

        void GameplayUIController::render()
        {
            std::cout << "Rendering UI..." << std::endl;
            level_number_text->render();
            score_text->render();
            time_complexity_text->render();
            operation_text->render();
        }

        void GameplayUIController::show()
        {
            level_number_text->show();
            score_text->show();
            time_complexity_text->show();
            operation_text->show();
        }

        void GameplayUIController::destroy()
        {
            delete (level_number_text);
            delete (score_text);
            delete(time_complexity_text);
            delete(operation_text);
        }
    }
}