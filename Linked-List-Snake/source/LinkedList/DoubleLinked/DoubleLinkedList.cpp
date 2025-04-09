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
		}

		void DoubleLinkedList::insertNodeAtIndex(int index)
		{
		}

		void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
		{
		}

		void DoubleLinkedList::removeNodeAtTail()
		{
		}

		void DoubleLinkedList::removeNodeAtHead()
		{
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


