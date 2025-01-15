/*
二叉树

*/
#include<iostream>
#include<stack>

typedef struct {
	int value;
	Node left;
	Node right;
}*Node;

/*非递归的中序遍历*/
void inOrderUnRecur(Node head) {
	if (head != NULL) {
		std::stack<Node> stk;
		while (!stk.empty() || head != NULL) {
			if (head != NULL) {
				stk.push(head);
				head = head->left;
			}
			else {
				head = stk.top();
				stk.pop();
				std::cout << head->value;
				head = head->right;
			}
		}
	}
}