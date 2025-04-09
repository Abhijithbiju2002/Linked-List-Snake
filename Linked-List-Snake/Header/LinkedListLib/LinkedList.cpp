#include "LinkedList.h"

namespace LinkedListLib {

	int LinkedList::findMiddleNode()
	{
        Node* slow = head_node;
        Node* fast = head_node;
        int midIndex = 0;  // This will track the index of the middle node.

        // Move fast pointer at 2x speed and slow pointer at 1x speed.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            midIndex++;
        }

        // Now, slow is at the middle node
        return midIndex;
	}

}
