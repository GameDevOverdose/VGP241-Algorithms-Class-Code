#include <iostream>
#include <algorithm>
#include <array>
#include <assert.h>

class IPAddress
{
public:
	IPAddress()
	{
		for (int i = 0; i < 4; ++i)
		{
			mAddress[i] = rand() % 1000;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const IPAddress& a)
	{
		std::cout << a.mAddress[0] << "." << a.mAddress[1] << "." << a.mAddress[2] << "." << a.mAddress[3];
		return os;
	}

	bool operator<(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; ++i)
		{
			if (mAddress[i] != rhs.mAddress[i])
			{
				return mAddress[i] < rhs.mAddress[i];
			}
		}

		return false;
	}

	bool operator<=(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; ++i)
		{
			if (mAddress[i] > rhs.mAddress[i])
			{
				return false;
			}
		}
	}

	bool operator==(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; ++i)
		{
			if (mAddress[i] != rhs.mAddress[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator>=(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; ++i)
		{
			if (mAddress[i] < rhs.mAddress[i])
			{
				return false;
			}
		}
	}

	bool operator>(const IPAddress& rhs) const
	{
		for (int i = 0; i < 4; ++i)
		{
			if (mAddress[i] != rhs.mAddress[i])
			{
				return mAddress[i] > rhs.mAddress[i];
			}
		}

		return false;
	}

private:
	int mAddress[4];
};

//----------------------------------------------------------

struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

int gCounter = 0;

Node* CreateNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}

Node* Insert(Node* node, int data)
{
	if (node == nullptr)
	{
		return CreateNode(data);
	}

	if (data < node->data)
	{
		node->left = Insert(node->left, data);
	}
	else if(data > node->data)
	{
		node->right = Insert(node->right, data);
	}
	else
	{
		assert(false, "Data must be unique.");
	}

	return node;
}

bool Search(Node* node, int data)
{
	if (node == nullptr)
	{
		return false;
	}

	if (node->data == data)
	{
		return true;
	}

	if (data < node->data)
	{
		return Search(node->left, data);
	}
	
	return Search(node->right, data);
}

Node* GetMinNode(Node* node)
{
	Node* minNode = node;

	while (minNode != nullptr && minNode->left != nullptr)
	{
		++gCounter;
		minNode = minNode->left;
	}

	return minNode;
}

Node* GetMaxNode(Node* node)
{
	Node* maxNode = node;

	while (maxNode != nullptr && maxNode->right != nullptr)
	{
		++gCounter;
		maxNode = maxNode->right;
	}

	return maxNode;
}

Node* Delete(Node* node, int data)
{
	if (node == nullptr)
	{
		return node;
	}

	if (data < node->data)
	{
		node->left = Delete(node->left, data);
	}
	else if(data > node->data)
	{
		node->right = Delete(node->right, data);
	}
	else
	{
		// check to see if a node has a child
		if (node->left == nullptr)
		{
			Node* temp = node->right;
			delete node;
			node = nullptr;
			return temp;
		}
		else if(node->right == nullptr)
		{
			Node* temp = node->left;
			delete node;
			node = nullptr;

			return temp;
		}

		// find the node to replace from the children
		Node* temp = GetMinNode(node->right);
		node->data = temp->data;
		node->right = Delete(node->right, temp->data);
	}

	return node;
}

void PrintInOrder(Node* root)
{
	if (root != nullptr)
	{
		PrintInOrder(root->left);
		std::cout << root->data << " ";
		PrintInOrder(root->right);
	}
}

void PrintReverseOrder(Node* root)
{
	if (root != nullptr)
	{
		PrintReverseOrder(root->right);
		std::cout << root->data << " ";
		PrintReverseOrder(root->left);
	}
}

//-------------------------------------------------------------------------


struct AVLNode
{
	IPAddress data;
	AVLNode* left = nullptr;
	AVLNode* right = nullptr;
	int height = 0;
};

AVLNode* CreateAVLNode(IPAddress data)
{
	AVLNode* newNode = new AVLNode();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

void PrintInOrder(AVLNode* root)
{
	if (root != nullptr)
	{
		PrintInOrder(root->left);
		std::cout << root->data << "\n";
		PrintInOrder(root->right);
	}
}

void PrintReverseOrder(AVLNode* root)
{
	if (root != nullptr)
	{
		PrintReverseOrder(root->right);
		std::cout << root->data << "\n";
		PrintReverseOrder(root->left);
	}
}

bool Search(AVLNode* node, IPAddress data)
{
	if (node == nullptr)
	{
		return false;
	}

	if (node->data == data)
	{
		return true;
	}

	if (data < node->data)
	{
		Search(node->left, data);
	}

	Search(node->right, data);
}

AVLNode* GetMinNode(AVLNode* root)
{
	AVLNode* minNode = root;

	while (minNode != nullptr && minNode->left != nullptr)
	{
		minNode = minNode->left;
	}

	return minNode->left;
}

AVLNode* GetMaxNode(AVLNode* root)
{
	AVLNode* maxNode = root;

	while (maxNode != nullptr && maxNode->right != nullptr)
	{
		maxNode = maxNode->right;
	}

	return maxNode->right;
}

int NodeHeight(AVLNode* node)
{
	if (node != nullptr)
	{
		return node->height;
	}
	return 0;
}

int BalanceFactor(AVLNode* node)
{
	if (node != nullptr)
	{
		return NodeHeight(node->left) - NodeHeight(node->right);
	}
	return 0;
}

AVLNode* RotateRight(AVLNode* y)
{
	AVLNode* x = y->left;
	AVLNode* temp = x->right;
	x->right = y;
	y->left = temp;
	y->height = std::max(NodeHeight(y->left), NodeHeight(y->right) + 1);
	x->height = std::max(NodeHeight(x->left), NodeHeight(x->right) + 1);
	return x;
}

AVLNode* RotateLeft(AVLNode* x)
{
	AVLNode* y = x->right;
	AVLNode* temp = y->left;
	y->left = x;
	x->right = temp;
	x->height = std::max(NodeHeight(x->left), NodeHeight(x->right) + 1);
	y->height = std::max(NodeHeight(y->left), NodeHeight(y->right) + 1);
	return y;
}

AVLNode* Insert(AVLNode* node, IPAddress data)
{
	if (node == nullptr)
	{
		return CreateAVLNode(data);
	}

	if (data < node->data)
	{
		node->left = Insert(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Insert(node->right, data);
	}
	else
	{
		assert(false, "Data must be unique.");
	}

	node->height = 1 + std::max(NodeHeight(node->left), NodeHeight(node->right));
	int balanceFactor = BalanceFactor(node);

	// Case 1, left is too long
	if (balanceFactor > 1 && data < node->left->data)
	{
		//return rotate right
		return RotateRight(node);
	}

	// Case 4, right is too long
	if (balanceFactor < -1 && data > node->right->data)
	{
		//return rotate left
		return RotateLeft(node);
	}

	// Case 2, right arm of the left side is too long
	if (balanceFactor > 1 && data > node->left->data)
	{
		//rotate left
		//return rotate right
		node->left = RotateLeft(node->left);
		return RotateRight(node);
	}

	// Case 3, left arm of the right side is too long
	if (balanceFactor < -1 && data < node->right->data)
	{
		//rotate right
		//return rotate left
		node->right = RotateRight(node->right);
		return RotateLeft(node);
	}

	return node;
}

AVLNode* Delete(AVLNode* node, IPAddress data)
{
	if (node == nullptr)
	{
		return node;
	}

	if (data < node->data)
	{
		node->left = Delete(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Delete(node->right, data);
	}
	else
	{
		if (node->left == nullptr)
		{
			AVLNode* temp = node->right;
			delete node;
			node = nullptr;
			return temp;
		}

		if (node->right == nullptr)
		{
			AVLNode* temp = node->left;
			delete node;
			node = nullptr;
			return temp;
		}

		AVLNode* temp = GetMinNode(node->right);
		node->data = temp->data;
		node->right = Delete(node->right, temp->data);

		node->height = 1 + std::max(NodeHeight(node->left), NodeHeight(node->right));
		int balanceFactor = BalanceFactor(node);

		if (balanceFactor > 1 && BalanceFactor(node->left) >= 0)
		{
			return RotateRight(node);
		}

		if (balanceFactor < -1 && BalanceFactor(node->right) <= 0)
		{
			return RotateLeft(node);
		}

		if (balanceFactor > 1 && BalanceFactor(node->left) < 0)
		{
			node->left = RotateLeft(node->left);
			return RotateRight(node);
		}

		if (balanceFactor < -1 && BalanceFactor(node->right) > 0)
		{
			node->right = RotateRight(node->right);
			return RotateLeft(node);
		}
	}

	return node;
}

//-------------------------------------------------------------------------

void Exercise1()
{
	std::cout << "Binary Search Tree: \n\n";

	Node* root = nullptr;

	for (int i = 0; i < 20; ++i)
	{
		int data = 1 + (rand() % 1000);

		while (Search(root, data))
		{
			data = 1 + (rand() % 1000);
		}

		std::cout << data << " ";
		root = Insert(root, data);
	}

	std::cout << "\n\n";
	PrintInOrder(root);
	std::cout << "\n\n";
	PrintReverseOrder(root);

	Delete(root, 335);
	std::cout << "\n\n";
	PrintInOrder(root);

	Delete(root, 501);
	Delete(root, 725);
	std::cout << "\n\n";
	PrintInOrder(root);

	gCounter = 0;
	std::cout << "\n\nMin Value: " << GetMinNode(root)->data << "\tNum Tested: " << gCounter;
	gCounter = 0;
	std::cout << "\nMax Value: " << GetMaxNode(root)->data << "\tNum Tested: " << gCounter;

	std::cout << "\n";
}

void Exercise2()
{
	Node* root = nullptr;

	for (int i = 0; i < 100; i++)
	{
		int data = rand() % 100000000;

		root = Insert(root, data);
	}

	PrintInOrder(root);
	std::cout << "\n\n";
	PrintReverseOrder(root);
	std::cout << "\n\n";

	std::cout << "Starting Root Node: " << root->data << "\n";

	for (int i = 0; i < 20; i++)
	{
		root = Delete(root, root->data);
		std::cout << "New Root Node: " << root->data << "\n";
	}

	PrintInOrder(root);
	std::cout << "\n\n";
}

void Exercise3()
{
	//std::cout << "AVL Tree:\n";

	//AVLNode* root = nullptr;

	//for (int i = 0; i < 20; ++i)
	//{
	//	int data = 1 + (rand() % 1000000000000);

	//	while (Search(root, data))
	//	{
	//		data = 1 + (rand() % 100);
	//	}

	//	root = Insert(root, data);
	//}

	//root = Delete(root, 79);
	//root = Delete(root, 62);
	//root = Delete(root, 46);
	//root = Delete(root, 96);

	//PrintInOrder(root);
	//std::cout << "\n\n";
	//PrintReverseOrder(root);
	//std::cout << "\n\n";

	//std::cout << "Min Value: " << GetMinNode(root)->data << "\n";
	//std::cout << "Max Value: " << GetMaxNode(root)->data << "\n";
}

int main()
{
	AVLNode* root = nullptr;

	std::cout << "AVL Tree: \n";

	for (int i = 0; i < 10; ++i)
	{
		IPAddress newAddress;
		root = Insert(root, newAddress);
	}

	PrintInOrder(root);
}