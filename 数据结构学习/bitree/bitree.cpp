/*
������

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

/*�ݹ����������*/
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

/*�ǵݹ�Ķ���������*/
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

/*�����򣩿�����ȱ���*/
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

/*�����������չ���ҵ��ڵ���Ŀ���Ĳ����Ŀ*/
/*����1*/
int widthOrderAndMaxNum(Node head) {
	if (head == NULL) {
		return;
	}
	std::queue<Node> q;
	q.push(head);
	std::unordered_map<Node, int>levelMap;
	levelMap.insert(std::pair<Node,int>(head,1));//����һ������map�У���һ��
	int curLevel = 1;
	int curLevelNodes = 0;
	int max = INT_MIN; 
	while (!q.empty()) {
		head = q.front(); //ȡ�����е�һ����
		q.pop();
		int curNodelevel = levelMap[head];//��ȡ��ǰ�ڵ����ڲ���
		if (curNodelevel == curLevel) { //����ǣ���ǰ��Ľڵ����+1
			curLevelNodes++;
		}
		else { //�����ǰ�ڵ�Ĳ����뵱ǰ�������ȣ���ζ�Ž�����һ��ڵ�
			max = std::max(max, curLevelNodes);
			curLevel += 1;
			curLevelNodes = 0;
		}
		/*����Ƿ����ӽڵ㣬�о�ѹ����У������ϣ��map*/
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

/*������*/
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


/*�ж��Ƿ�����������*/
/*
ʹ�ÿ�����ȱ���
��Ҫ����һ������
1.���һ���ڵ������ҽڵ�û����ڵ㣬��false
2.��������ӽڵ㲻˫ȫ��ֻ����ڵ㣬û���нڵ㣬��ô֮������нڵ㶼������Ҷ�ڵ�
*/


/*
�ж��Ƿ���������������
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