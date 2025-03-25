#include "../../Header/LinkedList/SingleLinkedList.h"
#include "../../Header/Player/BodyPart.h"
#include"../../Header/Level/LevelView.h"
#include <iostream>

namespace LinkedList {
	using namespace Player;

	SingleLinkedList::SingleLinkedList() {

		head_node = nullptr;
	}
	SingleLinkedList::~SingleLinkedList() = default;

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction direction) {
		

		//std::cout << "node width " << node_width << std::endl;
		//std::cout << "node height " << node_height << std::endl;
		////std::cout << "default direct. " << default_direction << std::endl;
        //      std::cout << "default position x " << default_position.x
		//	<<"default postion y "<< default_position.y << std::endl;

		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
		//createHeadNote();
		///for (int i = 0; i < 5; i++) {
		//insertNodeAtTail();
		//}
		
	}
	void SingleLinkedList::render() {

		Node* cur_node = head_node;
		
		while (cur_node != nullptr) {
			
			cur_node->body_part.render();
			cur_node = cur_node->next;
		}
		//head_node->body_part.render();
		
	}
	
	void SingleLinkedList::createHeadNote() {
		head_node = createNode();
		head_node->body_part.initialize(node_width, node_height, default_position, default_direction);
		return;
	}
	sf::Vector2i SingleLinkedList::getNewNodePosition(Node* reference_node) {

		Direction reference_direction = reference_node->body_part.getDirection();
		sf::Vector2i reference_position = reference_node->body_part.getPosition();

		switch (reference_direction) {
		case Direction::UP:
			return sf::Vector2i(reference_position.x, reference_position.y - 1);
			break;
		case Direction::DOWN:
			return sf::Vector2i(reference_position.x, reference_position.y + 1);
			break;
		case Direction::LEFT:
			return sf::Vector2i(reference_position.x + 1, reference_position.y);
			break;
		case Direction::RIGHT:
			return sf::Vector2i(reference_position.x - 1, reference_position.y);
			break;
		}
		return default_position;
	}
	void SingleLinkedList::insertNodeAtTail() {

		Node* new_node = createNode();
		Node* cur_node = head_node;

		if (cur_node == nullptr) {
			head_node = new_node;
			new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
			return;
		}
		// Traverse to the end of the list 
		while (cur_node->next != nullptr) {
			cur_node = cur_node->next;
			
		}
		// Attach the new node at the end
		cur_node->next = new_node;
		new_node->body_part.initialize(node_width, node_height, getNewNodePosition(cur_node),
		cur_node->body_part.getDirection());
		
	}
	Node* SingleLinkedList::createNode() {

		return new Node();
	}

}