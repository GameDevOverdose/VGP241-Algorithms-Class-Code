#include <iostream>

struct Node
{
	int mData = 0;
	Node* mChild = nullptr;
};

Node* AddToList(Node* parent, int value)
{
	Node* newNode = new Node();
	newNode->mData = value;

	if (parent != nullptr)
	{
		parent->mChild = newNode;
	}

	return newNode;
}

void DeleteList(Node* node)
{
	if (node != nullptr)
	{
		DeleteList(node->mChild);
		delete node;
		node = nullptr;
	}
}

bool LinkedListIsCyclical(Node* root)
{
	int count = 0;
	Node* tmp = root;

	while (tmp != nullptr)
	{
		tmp = tmp->mChild;

		if (count != 0 && tmp == root)
		{
			return true;
		}

		++count;
	}

	return false;
}

int main()
{
	Node* prevNode = nullptr;
	Node* root = nullptr;

	for (int i = 0; i < 30; ++i)
	{
		prevNode = AddToList(prevNode, i);

		if (root == nullptr)
		{
			root = prevNode;
		}

		prevNode->mChild = root;
	}

	std::cout << "\nIs the linked list cyclical? " << (LinkedListIsCyclical(root) ? "Yes" : "No") << "\n";

	if (!LinkedListIsCyclical(root))
	{
		Node* tmp = root;

		std::cout << "List of numbers: \n\n";

		while (tmp != nullptr)
		{
			std::cout << tmp->mData << "\n";
			tmp = tmp->mChild;
		}

		DeleteList(root);
	}
}