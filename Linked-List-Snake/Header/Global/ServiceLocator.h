#pragma once
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Level/LevelService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Event/EventService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Event::EventService* event_service;
        Graphics::GraphicService* graphic_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;
        Level::LevelService* level_service;
        Player::PlayerService* player_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Event::EventService* getEventService();
        Graphics::GraphicService* getGraphicService();
        Sound::SoundService* getSoundService();
        UI::UIService* getUIService();
        Time::TimeService* getTimeService();
        Level::LevelService* getLevelService();
        Player::PlayerService* getPlayerService();

        void deleteServiceLocator();
    };
}