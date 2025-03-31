#pragma once
#include "../../Header/Player/BodyPart.h"

namespace LinkedList {

	using namespace Player;

	struct Node
	{
		BodyPart body_part;
		Node* next = nullptr;

	};
}
