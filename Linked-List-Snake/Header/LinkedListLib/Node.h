#pragma once
#include "../../Header/Player/BodyPart.h"

namespace LinkedListLib {

	using namespace Player;

	struct Node
	{
		BodyPart body_part;
		Node* next = nullptr;


	};
}
