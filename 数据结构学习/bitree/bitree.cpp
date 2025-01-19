/*
二叉树

*/
#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
typedef struct {
	int value;
	Node left;
	Node right;
}*Node;

/*递归遍历二叉树*/
void preOrderRecur(Node head) {
	if (head == NULL)
		return;
	std::cout << head->value;
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

void inOrderRecur(Node head) {
	if (head == NULL)
		return;
	preOrderRecur(head->left);
	std::cout << head->value;
	preOrderRecur(head->right);
}

void postOrderRecur(Node head) {
	if (head == NULL)
		return;
	preOrderRecur(head->left);
	preOrderRecur(head->right);
	std::cout << head->value;

}

/*非递归的二叉树遍历*/
void preOrderUnRecur(Node head) {
	if (head != NULL) {
		std::stack<Node> stk;
		stk.push(head);
		while (!stk.empty()) {
			head = stk.top();
			stk.pop();
			std::cout << head->value;
			if (head->right) {
				stk.push(head->right);
			}
			if (head->left) {
				stk.push(head->left);
			}
		}
	}
}

void inOrderUnRecur(Node head) {
	if (head != NULL) {
		std::stack<Node> stk;
		while (!stk.empty()) {
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

void postOrderUnRecur(Node head) {
	if (head != NULL) {
		std::stack<Node>stk1;
		std::stack<Node>stk2;
		stk1.push(head);
		while (!stk1.empty()) {
			head = stk1.top();
			stk1.pop();
			stk2.push(head);
			if (head->right) {
				stk1.push(head->right);
			}
			if (head->left) {
				stk1.push(head->left);
			}
		}
		while (!stk2.empty()) {
			head = stk2.top();
			std::cout << head->value << " ";
			stk2.pop();
		}
	}
	
}

/*（层序）宽度优先遍历*/
void widthOrder(Node head) {
	if (head == NULL) {
		return;
	}
	std::queue<Node> q;
	q.push(head);
	while (!q.empty()) {
		head = q.front();
		q.pop();
		std::cout << head->value;
		if (head->left) { q.push(head->left); }
		if (head->right) { q.push(head->right); }
	}
}

/*层序遍历的拓展：找到节点数目最多的层的数目*/
/*方法1*/
int widthOrderAndMaxNum(Node head) {
	if (head == NULL) {
		return;
	}
	std::queue<Node> q;
	q.push(head);
	std::unordered_map<Node, int>levelMap;
	levelMap.insert(std::pair<Node,int>(head,1));//将第一个放入map中，第一层
	int curLevel = 1;
	int curLevelNodes = 0;
	int max = INT_MIN; 
	while (!q.empty()) {
		head = q.front(); //取出队列的一个数
		q.pop();
		int curNodelevel = levelMap[head];//获取当前节点所在层数
		if (curNodelevel == curLevel) { //如果是，当前层的节点个数+1
			curLevelNodes++;
		}
		else { //如果当前节点的层数与当前层数不等，意味着进入下一层节点
			max = std::max(max, curLevelNodes);
			curLevel += 1;
			curLevelNodes = 0;
		}
		/*检查是否有子节点，有就压入队列，加入哈希表map*/
		if (head->left) { 
			q.push(head->left); 
			levelMap.insert(std::pair<Node,int>(head->left, curNodelevel+1));
		}
		if (head->right) { 
			q.push(head->right); 
			levelMap.insert(std::pair<Node, int>(head->right, curNodelevel + 1));
		}
	}

	return max;
}

/*方法二*/
int widthOrderAndMaxNum2(Node head) {
	if (head ==NULL) {
		return;
	}
	Node curEndNode = head;
	Node nextEndNode = NULL;
	int max = INT_MIN;
	int curLevelNodes = 0;
	std::queue<Node> queue;
	queue.push(head);
	while (!queue.empty()) {
		Node cur = queue.front();
		queue.pop();
		curLevelNodes++;
		if (head->left) {
			queue.push(head->left);
			nextEndNode = head->left;
		}
		if (head->right) {
			queue.push(head->right);
			nextEndNode = head->left;
		}
		if (cur == curEndNode) {
			curEndNode == nextEndNode;
			nextEndNode = NULL;
			max = std::max(curLevelNodes, max);
			curLevelNodes = 0;
		}
	}
	return max;
}


/*判断是否是满二叉树*/
/*
使用宽度优先遍历
需要满足一下条件
1.如果一个节点有有右节点没有左节点，则false
2.如果左右子节点不双全，只有左节点，没有有节点，那么之后的所有节点都必须是叶节点
*/


/*
判断是否是搜索二叉树：
*/
int isBST(Node head) {
	if (head == NULL)
		return;
	int preValue = INT_MIN;
	int isLeftBst = isBST(head->left);
	if (!isLeftBst) return false;
	if (head->value < preValue) {
		return false;
	}
	else {
		preValue = head->value;
	}
	return isBST(head->right); 
}

int isBSTUnRecur(Node head) {
	int preValue = INT_MIN;
	if (head != NULL) {
		std::stack<Node> stk;
		while (!stk.empty()) {
			if (head != NULL) {
				stk.push(head);
				head = head->left;
			}
			else {
				head = stk.top();
				stk.pop();
				if (head->value <= preValue) {
					return false;
				}
				else {
					preValue = head->value;
				}
				head = head->right;
			}
		}
	}
}