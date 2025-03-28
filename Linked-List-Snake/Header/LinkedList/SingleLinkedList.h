#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../Header/LinkedList/Node.h"

namespace LinkedList {

	class SingleLinkedList {

	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();

		

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();

		void createHeadNote();
		Vector2i getNewNodePosition(Node* refernce_node);
		void insertNodeAtTail();
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();
		void removeNodeAtHead();
		void removeAllNodes();
	};
}
