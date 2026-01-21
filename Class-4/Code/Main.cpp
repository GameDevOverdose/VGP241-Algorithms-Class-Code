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

//bool LinkedListIsCyclical(Node* root)
//{
//	int count = 0;
//	Node* tmp = root;
//
//	while (tmp != nullptr)
//	{
//		tmp = tmp->mChild;
//
//		if (count != 0 && tmp == root)
//		{
//			return true;
//		}
//
//		++count;
//	}
//
//	return false;
//}

bool LinkedListIsCyclical(Node* root)
{
	Node* slowNode = root;
	Node* fastNode = root;

	while (slowNode != nullptr && fastNode != nullptr && fastNode->mChild != nullptr)
	{
		slowNode = slowNode->mChild;
		fastNode = fastNode->mChild->mChild;

		if (slowNode == fastNode)
		{
			return true;
		}
	}
}

void LinkedListsMain()
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
	}

	std::cout << "\nIs the linked list cyclical: " << (LinkedListIsCyclical(root) ? "Yes" : "No") << "\n\n";

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

struct Vector2
{
	int x = 0;
	int y = 0;
};

struct KDNode
{
	Vector2 mData;
	KDNode* mLeft = nullptr;
	KDNode* mRight = nullptr;
};

KDNode* Insert(const Vector2& v, KDNode* prev, int k)
{
	if (prev == nullptr)
	{
		KDNode* newNode = new KDNode();
		newNode->mData = v;
		return newNode;
	}

	if (prev->mData.x == v.x && prev->mData.y == v.y)
	{
		std::cout << "[ERROR] Node already exists in the tree!\n";
		return prev;
	}

	//We are looking at the first dimension which is x
	if (k == 0)
	{
		//k % 2 because it is 2 dimensions, x and y, so k will then be y
		if (v.x < prev->mData.x)
		{
			prev->mLeft = Insert(v, prev->mLeft, (k + 1) % 2);
		}
		else
		{
			prev->mRight = Insert(v, prev->mRight, (k + 1) % 2);
		}
	}
	//We are looking at the second dimension, which is y
	else if(k == 1)
	{
		if (v.y < prev->mData.y)
		{
			prev->mLeft = Insert(v, prev->mLeft, (k + 1) % 2);
		}
		else
		{
			prev->mLeft = Insert(v, prev->mRight, (k + 1) % 2);
		}
	}
	//Should not be here, may need to make a more dynamic setup for dimensions
	else
	{
		std::cout << "[ERROR] dimension not set up\n";
	}

	return prev;
}

Vector2 Minimum(const Vector2& a, const Vector2& b, const Vector2& c, int dim)
{
	float aDimValue = (dim == 0) ? a.x : a.y;
	float bDimValue = (dim == 0) ? b.x : b.y;
	float cDimValue = (dim == 0) ? c.x : c.y;

	if (aDimValue < bDimValue && aDimValue < cDimValue)
	{
		return a;
	}
	else if (bDimValue < aDimValue && bDimValue < cDimValue)
	{
		return b;
	}

	return c;
}

//Finding min in the specific dimension
//Dim can be 0, x dimension
//Dim can be 1, y dimension
int gRecursiveCount = 0;
Vector2 FindMin(KDNode* node, int dim, int k)
{
	gRecursiveCount++;

	if (node == nullptr)
	{
		Vector2 invalid;
		invalid.x = INT_MAX;
		invalid.y = INT_MAX;
		return invalid;
	}
	
	if (k == dim)
	{
		if (node->mLeft == nullptr)
		{
			return node->mData;
		}
		else
		{
			return FindMin(node->mLeft, dim, (k + 1) % 2);
		}
	}
	else
	{
		return Minimum(FindMin(node->mLeft, dim, (k + 1) % 2), FindMin(node->mRight, dim, (k + 1) % 2), node->mData, dim);
	}
}

void PrintRange(const Vector2& minRange, const Vector2& maxRange, KDNode* node, int k)
{
	gRecursiveCount++;

	if (node != nullptr)
	{
		if (minRange.x <= node->mData.x && minRange.y <= node->mData.y && node->mData.x <= maxRange.x && node->mData.y <= maxRange.y)
		{
			std::cout << "(" << node->mData.x << ", " << node->mData.y << ")\n";
		}

		if (k == 0)
		{
			if (minRange.x < node->mData.x)
			{
				PrintRange(minRange, maxRange, node->mLeft, (k + 1) % 2);
			}

			if (node->mData.x < maxRange.x)
			{
				PrintRange(minRange, maxRange, node->mRight, (k + 1) % 2);
			}
		}
		else
		{
			if (minRange.y < node->mData.y)
			{
				PrintRange(minRange, maxRange, node->mLeft, (k + 1) % 2);
			}

			if (node->mData.y < minRange.y)
			{
				PrintRange(minRange, maxRange, node->mRight, (k + 1) % 2);
			}
		}
	}
}

KDNode* Delete(const Vector2& v, KDNode* node, int k)
{
	if (node == nullptr)
	{
		std::cout << "[ERROR] NODE WAS NOT FOUND\n";
		return node;
	}

	if (v.x == node->mData.x && v.y == node->mData.y)
	{
		if (node->mRight != nullptr)
		{
			node->mData = FindMin(node->mRight, k, (k + 1) % 2);
			node->mRight = Delete(node->mData, node->mRight, (k + 1) % 2);
		}
		else if(node->mRight != nullptr)
		{
			node->mData = FindMin(node->mLeft, k, (k + 1) % 2);
			node->mRight = Delete(node->mData, node->mLeft, (k + 1) % 2);
		}
		else
		{
			delete node;
			node = nullptr;
		}
	}
	else
	{
		if (k == 0)
		{
			if (v.x < node->mData.x)
			{
				node->mLeft = Delete(v, node->mLeft, (k + 1) % 2);
			}
			else
			{
				node->mRight = Delete(v, node->mRight, (k + 1) % 2);
			}
		}
		else
		{
			if (v.y < node->mData.y)
			{
				node->mLeft = Delete(v, node->mLeft, (k + 1) % 2);
			}
			else
			{
				node->mRight = Delete(v, node->mRight, (k + 1) % 2);
			}
		}
	}

	return node;
}

void PrintDataAtLevel(KDNode* node, int level, const std::string& side)
{
	if (node == nullptr)
	{
		return;
	}

	if (level == 0)
	{
		std::cout << side << "(" << node->mData.x << ", " << node->mData.y << ") ";
	}
	else
	{
		PrintDataAtLevel(node->mLeft, level - 1, "L");
		PrintDataAtLevel(node->mRight, level - 1, "R");
	}
}

void PrintTree(KDNode* tree)
{
	std::cout << "\n\n\n\n\nPrinting Tree: \n\n";

	for (int i = 0; i < 20; i++)
	{
		PrintDataAtLevel(tree, i, "ROOT");
		std::cout << "\n";
	}
}

void DeleteKDTree(KDNode* node)
{
	if (node != nullptr)
	{
		DeleteKDTree(node->mLeft);
		DeleteKDTree(node->mRight);
		delete node;
		node = nullptr;
	}
}

int main()
{
	Vector2 v;
	Vector2 deleteVector;
	KDNode* root = nullptr;

	int totalValues = 10;
	int minValue = 0;
	int maxValue = 200;

	int randomDeleteNodeIndex = rand() % totalValues;

	for (int i = 0; i < totalValues; ++i)
	{
		v.x = rand() % maxValue;
		v.y = rand() % maxValue;

		KDNode* newNode = Insert(v, root, 0);

		if (root == nullptr)
		{
			root = newNode;
		}

		std::cout << "(" << v.x << ", " << v.y << ")\n";

		if (i = randomDeleteNodeIndex)
		{
			deleteVector = v;
		}
	}

	//PrintTree(root);
	gRecursiveCount = 0;
	Vector2 minInX = FindMin(root, 0, 0);
	std::cout << "Iterations: " << gRecursiveCount << "\n";

	gRecursiveCount = 0;
	Vector2 minInY = FindMin(root, 1, 0);
	std::cout << "Iterations: " << gRecursiveCount << "\n";

	std::cout << "\n\nMin in the X: (" << minInX.x << ", " << minInX.y << ")\n";
	std::cout << "Min in the Y: (" << minInY.x << ", " << minInY.y << ")\n";

	std::cout << "\n\n";

	Vector2 minRange;
	Vector2 maxRange;

	minRange.x = (rand() % 101) + 100;
	minRange.y = (rand() % 101) + 100;

	maxRange.x = (rand() % 101) + 300;
	maxRange.y = (rand() % 101) + 300;

	std::cout << "Find in range: Min(" << minRange.x << ", " << minRange.y << ") : Max(" << maxRange.x << ", " << maxRange.y << ")\n";
	
	gRecursiveCount = 0;
	PrintRange(minRange, maxRange, root, 0);
	std::cout << "Iterations: " << gRecursiveCount << "\n";

	Delete(deleteVector, root, 0);
	minRange.x = minValue;
	minRange.y = minValue;
	maxRange.x = maxValue;
	maxRange.y = maxValue;

	std::cout << "Delete Node: (" << deleteVector.x << ", " << deleteVector.y << ")\n";

	PrintRange(minRange, maxRange, root, 0);
	

	DeleteKDTree(root);
}