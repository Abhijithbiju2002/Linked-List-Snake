#include "../../Header/LinkedListLib/DoubleLinked/DoubleLinkedList.h"
#include "../../Header/LinkedListLib/DoubleLinked/DoubleNode.h"

namespace LinkedListLib {

	namespace DoubleLinked {

		Node* DoubleLinkedList::createNode() {
			return new DoubleNode();
		}

		DoubleLinkedList::DoubleLinkedList()
		{
		}

		DoubleLinkedList::~DoubleLinkedList()
		{
		}

		void DoubleLinkedList::insertNodeAtTail()
		{
			linked_list_size++;
			Node* new_node = createNode();
			Node* cur_node = head_node;

			if (cur_node == nullptr) {
				head_node = new_node;
				static_cast<DoubleNode*>(new_node)->previous = nullptr;
				initializeNode(new_node, nullptr, Operation::TAIL);
				return;
			}
			while (cur_node->next != nullptr) {

				cur_node = cur_node->next;
			}
			cur_node->next = new_node;
			static_cast<DoubleNode*>(new_node)->previous = cur_node;
			initializeNode(new_node, cur_node, Operation::TAIL);
		}

		void DoubleLinkedList::insertNodeAtHead()
		{
			linked_list_size++;
			Node* new_node = createNode();


			if (head_node == nullptr) {
				head_node = new_node;
				static_cast<DoubleNode*>(new_node)->previous = nullptr;
				initializeNode(new_node, nullptr, Operation::HEAD);
				return;
			}

			initializeNode(new_node, head_node, Operation::HEAD);

			new_node->next = head_node;
			static_cast<DoubleNode*>(head_node)->previous = new_node;

			head_node = new_node;
		}

		void DoubleLinkedList::insertNodeAtMiddle()
		{
			if (!head_node) {
				insertNodeAtHead();
				return;
			}
			int midIndex = findMiddleNode();
			insertNodeAtIndex(midIndex);
		}

		void DoubleLinkedList::insertNodeAtIndex(int index)
		{
			if (index <0 || index > linked_list_size)
				return;

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
			// Insert the new node between prev and cur
			new_node->next = cur;
			if (cur)
				static_cast<DoubleNode*>(cur)->previous = new_node;

			prev->next = new_node;
			static_cast<DoubleNode*>(new_node)->previous = prev;

			initializeNode(new_node, prev, Operation::MID);
			shiftNodesAfterInsertion(new_node, cur, prev);
			linked_list_size++;
		}

		void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
		{
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

		void DoubleLinkedList::removeNodeAtTail()
		{
			if (head_node == nullptr)return;
			linked_list_size--;

			Node* cur_node = head_node;

			if (cur_node->next == nullptr) {
				removeNodeAtHead();
				return;
			}
			while (cur_node->next != nullptr)
			{
				cur_node = cur_node->next;
			}

			Node* previous = static_cast<DoubleNode*>(cur_node)->previous;
			previous->next = nullptr;
			delete(cur_node);

		}

		void DoubleLinkedList::removeNodeAtHead()
		{
			linked_list_size--;

			Node* cur_node = head_node;
			head_node = head_node->next;

			if (head_node != nullptr) {
				static_cast<DoubleNode*>(head_node)->previous = nullptr;
			}
			cur_node->next = nullptr;
			delete cur_node;
		}

		void DoubleLinkedList::removeNodeAtMiddle()
		{
		}

		void DoubleLinkedList::removeNodeAt(int index)
		{
		}

		void DoubleLinkedList::removeNodeAtIndex(int index)
		{
		}

		void DoubleLinkedList::removeAllNodes()
		{
		}

		void DoubleLinkedList::removeHalfNodes()
		{
		}

		void DoubleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
		{
		}

		Direction DoubleLinkedList::reverse()
		{
			return Direction();
		}

	}
}


