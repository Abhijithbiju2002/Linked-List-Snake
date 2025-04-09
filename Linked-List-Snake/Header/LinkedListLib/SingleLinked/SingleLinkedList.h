#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../Header/LinkedListLib/Node.h"

namespace LinkedListLib {

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

		int linked_list_size;

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
		void insertNodeAtHead();
		void insertNodeAtTail();
		void insertNodeAtIndex(int index);
		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		int findMiddleNode();
		void insertNodeAtMiddle();
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();
		void removeNodeAtHead();
		void removeAllNodes();
		Direction getReverseDirection(Direction reference_direction);
		//void insertNodeAt(int index);

		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);

		std::vector<sf::Vector2i> getNodePositionList();

		void shiftNodesAfterRemoval(Node* cur_node);

		void removeNodeAtIndex(int index);

		void removeNodeAt(int index);

		void removeNodeAtMiddle();

		void removeNodeAtTail();

		Node* findNodeAtIndex(int index);

		void removeHalfNodes();

		

		void reverseNodeDirections();

		Direction reverse();

		Node* getHeadNode();

		
	};
}
