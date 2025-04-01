#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../Header/LinkedList/Node.h"

namespace LinkedList {

	enum class Operation {
		HEAD,
		MID,
		TAIL,
	};
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

		void initializeNode(Node* new_node, Node* reference_node, Operation operation);

		void createHeadNote();
		Vector2i getNewNodePosition(Node* refernce_node);
		void insertNodeAtTail();
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();
		void removeNodeAtHead();
		void removeAllNodes();

		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);

		std::vector<sf::Vector2i> getNodePositionList();

		Node* getHeadNode();

		
	};
}
