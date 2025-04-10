#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ButtonView.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace UI {

	namespace LinkedListSelection {

		class LinkedListSelectionUIController : public Interface::IUIController {

		private:
			const float button_width = 400.f;
			const float button_height = 140.f;
			const float single_button_y = 500.f;
			const float double_button_y = 700.f;
			const float menu_button_y = 900.f;
			const float background_alpha = 85.f;

			UI::UIElement::ImageView* background_image;
			UI::UIElement::ButtonView* single_link_button;
			UI::UIElement::ButtonView* double_link_button;
			UI::UIElement::ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();
			float calculateLeftOffset();

			void singleLinkCallback();
			void doubleLinkCallback();
			void menuCallback();

			void destroy();

		public:
			LinkedListSelectionUIController();
			~LinkedListSelectionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};

	}


	
}
