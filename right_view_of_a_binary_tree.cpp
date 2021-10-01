

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printRightView(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		int n = q.size();

		while (n--) {

			Node* x = q.front();
			q.pop();

			// print the last node of each level
			if (n == 0) {
				cout << x->data << " ";
			}

			if (x->left)
				q.push(x->left);
			if (x->right)
				q.push(x->right);
		}
	}
}

int main()
{

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	printRightView(root);
}

