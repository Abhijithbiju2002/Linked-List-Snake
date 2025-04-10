#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../Header/LinkedListLib/Node.h"
#include "../../Header/LinkedListLib/LinkedList.h"

namespace LinkedListLib {
	namespace SingleLinked {

		class SingleLinkedList : public LinkedList {
		protected:
			Node* createNode() override;

			void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
			void shiftNodesAfterRemoval(Node* cur_node);
			void reverseNodeDirections();

		public:
			SingleLinkedList();
			~SingleLinkedList();

			void insertNodeAtHead() override;
			void insertNodeAtTail() override;
			void insertNodeAtIndex(int index) override;
			void insertNodeAtMiddle() override;

			void removeNodeAtHead() override;
			void removeNodeAtTail() override;
			void removeNodeAtIndex(int index);
			void removeNodeAt(int index) override;
			void removeNodeAtMiddle() override;
			void removeAllNodes()
				override;
			void removeHalfNodes() override;

			Direction reverse() override;

			// Optional: Override if you need custom behavior
			void updateNodeDirection(Direction direction_to_set) override;
			void updateNodePosition() override;

		};
	}
	
}
