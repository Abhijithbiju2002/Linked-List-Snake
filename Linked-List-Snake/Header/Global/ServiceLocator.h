#pragma once
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Level/LevelService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Element/ElementService.h"



namespace Global
{
    using namespace Event;
    using namespace Sound;
    using namespace Time;

    class ServiceLocator
    {
    private:
        EventService* event_service;
        Graphics::GraphicService* graphic_service;
        SoundService* sound_service;
        UI::UIService* ui_service;
        TimeService* time_service;
        Level::LevelService* level_service;
        Player::PlayerService* player_service;
        Element::ElementService* element_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        EventService* getEventService();
        Graphics::GraphicService* getGraphicService();
        SoundService* getSoundService();
        UI::UIService* getUIService();
        TimeService* getTimeService();
        Level::LevelService* getLevelService();
        Player::PlayerService* getPlayerService();
       Element::ElementService* getElementService();

        void deleteServiceLocator();
    };
}