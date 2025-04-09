#include "../../Header/LinkedListLib/SingleLinked/SingleLinkedList.h"
#include "../../Header/Player/BodyPart.h"
#include"../../Header/Level/LevelView.h"
#include <iostream>

namespace LinkedListLib{

	namespace SingleLinked {
		using namespace Player;


		SingleLinkedList::SingleLinkedList() {
			head_node = nullptr;
			linked_list_size = 0;
		}

		SingleLinkedList::~SingleLinkedList() {
			removeAllNodes();
		}

		Node* SingleLinkedList::createNode() {
			return new Node();
		}

		void SingleLinkedList::insertNodeAtHead() {
			Node* new_node = createNode();
			if (!head_node) {
				head_node = new_node;
				initializeNode(new_node, nullptr, Operation::HEAD);
			}
			else {
				initializeNode(new_node, head_node, Operation::HEAD);
				new_node->next = head_node;
				head_node = new_node;
			}
			linked_list_size++;
		}

		void SingleLinkedList::insertNodeAtTail() {
			//Node* new_node = createNode();
			//if (!head_node) {
			//	head_node = new_node;
			//	initializeNode(new_node, nullptr, Operation::TAIL);
			//}
			//else {
			//	Node* cur = head_node;
			//	while (cur->next) cur = cur->next;
			//	cur->next = new_node;
			//	initializeNode(new_node, cur, Operation::TAIL);
			//}
			//linked_list_size++;
			linked_list_size++;
			Node* new_node = createNode();
			Node* cur_node = head_node;

			if (cur_node == nullptr)
			{
				head_node = new_node;
				initializeNode(new_node, nullptr, Operation::TAIL);
				return;
			}

			while (cur_node->next != nullptr)
			{
				cur_node = cur_node->next;
			}

			cur_node->next = new_node;
			initializeNode(new_node, cur_node, Operation::TAIL);
		}

		void SingleLinkedList::insertNodeAtIndex(int index) {
			if (index < 0 || index > linked_list_size) return;

			if (index == 0) {
				insertNodeAtHead();
				return;
			}

			Node* new_node = createNode();
			Node* cur = head_node;
			Node* prev = nullptr;
			int current_index = 0;

			while (cur && current_index < index) {
				prev = cur;
				cur = cur->next;
				current_index++;
			}

			prev->next = new_node;
			new_node->next = cur;
			initializeNode(new_node, prev, Operation::TAIL);
			linked_list_size++;

			shiftNodesAfterInsertion(new_node, cur, prev);
		}

		void SingleLinkedList::insertNodeAtMiddle() {
			if (!head_node) {
				insertNodeAtHead();
				return;
			}
			insertNodeAtIndex(findMiddleNode());
		}

		void SingleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node) {
			Node* next = cur_node;
			Node* current = new_node;

			while (current && next) {
				current->body_part.setPosition(next->body_part.getPosition());
				current->body_part.setDirection(next->body_part.getDirection());

				prev_node = current;
				current = next;
				next = next->next;
			}
			if (current) {
				initializeNode(current, prev_node, Operation::TAIL);
			}
		}

		void SingleLinkedList::removeNodeAtHead() {
			if (!head_node) return;

			Node* temp = head_node;
			head_node = head_node->next;
			delete temp;
			linked_list_size--;
		}

		void SingleLinkedList::removeNodeAtTail() {
			if (!head_node) return;

			if (!head_node->next) {
				removeNodeAtHead();
				return;
			}

			Node* cur = head_node;
			while (cur->next->next) cur = cur->next;

			delete cur->next;
			cur->next = nullptr;
			linked_list_size--;
		}

		void SingleLinkedList::removeNodeAtIndex(int index) {
			if (index < 0 || index >= linked_list_size) return;

			if (index == 0) {
				removeNodeAtHead();
				return;
			}

			Node* cur = head_node;
			Node* prev = nullptr;
			int current_index = 0;

			while (cur && current_index < index) {
				prev = cur;
				cur = cur->next;
				current_index++;
			}

			if (!cur) return;

			prev->next = cur->next;
			shiftNodesAfterRemoval(cur);
			delete cur;
			linked_list_size--;
		}

		void SingleLinkedList::removeNodeAt(int index) {
			removeNodeAtIndex(index);
		}

		void SingleLinkedList::removeNodeAtMiddle() {
			if (!head_node) return;
			removeNodeAt(findMiddleNode());
		}

		void SingleLinkedList::removeAllNodes() {
			while (head_node) {
				removeNodeAtHead();
			}
		}

		void SingleLinkedList::removeHalfNodes() {
			if (linked_list_size <= 1) return;

			int half = linked_list_size / 2;
			Node* prev = findNodeAtIndex(half - 1);
			Node* cur = prev->next;

			while (cur) {
				Node* temp = cur;
				cur = cur->next;
				delete temp;
				linked_list_size--;
			}
			prev->next = nullptr;
		}

		void SingleLinkedList::shiftNodesAfterRemoval(Node* cur_node) {
			if (!cur_node) return;

			sf::Vector2i prev_pos = cur_node->body_part.getPosition();
			Direction prev_dir = cur_node->body_part.getDirection();

			cur_node = cur_node->next;

			while (cur_node) {
				sf::Vector2i temp_pos = cur_node->body_part.getPosition();
				Direction temp_dir = cur_node->body_part.getDirection();

				cur_node->body_part.setPosition(prev_pos);
				cur_node->body_part.setDirection(prev_dir);

				prev_pos = temp_pos;
				prev_dir = temp_dir;

				cur_node = cur_node->next;
			}
		}

		void SingleLinkedList::reverseNodeDirections() {
			Node* cur = head_node;
			while (cur) {
				cur->body_part.setDirection(getReverseDirection(cur->body_part.getPreviousDirection()));
				cur = cur->next;
			}
		}

		Direction SingleLinkedList::reverse() {
			Node* prev = nullptr;
			Node* cur = head_node;
			Node* next = nullptr;

			while (cur) {
				next = cur->next;
				cur->next = prev;
				prev = cur;
				cur = next;
			}

			head_node = prev;
			reverseNodeDirections();
			return head_node->body_part.getDirection();
		}

		void SingleLinkedList::updateNodeDirection(Direction direction_to_set) {
			Node* cur = head_node;
			while (cur) {
				Direction prev = cur->body_part.getDirection();
				cur->body_part.setDirection(direction_to_set);
				direction_to_set = prev;
				cur = cur->next;
			}
		}

		void SingleLinkedList::updateNodePosition() {
			Node* cur = head_node;
			while (cur) {
				cur->body_part.updatePosition();
				cur = cur->next;
			}





		}

	}
}