#include "huffman.h"
using namespace std;

void getHuffmanData(unordered_map<char, int>& data, string& text)
{
	string file_name = "huffman.txt";
	ifstream inputFile(file_name);
	if (!inputFile.is_open()) {
		cerr << "Error opening file: " << file_name << endl;
		exit(1);
	}
	char a;
	while (inputFile.get(a)) {
		unordered_map<char, int>::iterator it = data.find(a);
		if (it == data.end())
			data.insert(pair<char, int>(a, 1));
		else
			data[a]++;
	}

	inputFile.clear();
	inputFile.seekg(0, std::ios::beg);
	text = std::string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

	inputFile.close();
}

void generateCodes(HuffmanNode* root, string str, std::unordered_map<char, std::string>& huffmanCode)
{
	if (!root) {
		return;
	}

	//如果是叶子结点，保存哈弗曼编码
	if (!root->left && !root->right) {
		huffmanCode[root->data] = str;
	}

	//递归处理左子树和右子树
	generateCodes(root->left, str + '0', huffmanCode);
	generateCodes(root->right, str + '1', huffmanCode);
}

int calculateFixedLengthBits(const string& text) {
	return text.length() * 8;
}

int calculateHuffmanBits(const string& text, const std::unordered_map<char, std::string>& huffmanCode) {
	int totalBits = 0;
	for (const char c : text) {
		totalBits += huffmanCode.at(c).length();
	}
	return totalBits;
}

void buildHuffmanTree(const std::unordered_map<char, int>& charFreq, const string& text) {
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

	// 将每个字符极其频率作为单独节点插入小顶堆
	for (const auto& pair : charFreq) {
		minHeap.push(new HuffmanNode(pair.first, pair.second));
	}

	//合并节点直到剩下一个节点
	while (minHeap.size() > 1) {
		//取出最小的频率的两个节点
		HuffmanNode* left = minHeap.top();
		minHeap.pop();
		HuffmanNode* right = minHeap.top();
		minHeap.pop();

		HuffmanNode* newNode = new HuffmanNode('$', left->freq + right->freq);
		newNode->left = left;
		newNode->right = right;

		//将新节点插入小顶堆
		minHeap.push(newNode);
	}

	HuffmanNode* root = minHeap.top();

	//生成哈夫曼编码
	unordered_map<char, string> huffmanCodes;
	generateCodes(root, "", huffmanCodes);
	int count = 0;
	for (const auto& pair : huffmanCodes) {
		char c = pair.first;
		if (std::isprint(static_cast<unsigned char>(c))) {
			std::cout << "'" << c << "' : " << pair.second;
		}
		else {
			std::cout << "\\x" << std::hex << static_cast<int>(static_cast<unsigned char>(c)) << " : " << std::dec << pair.second;
		}
		count++;
		if (count % 4 == 0)
			cout << endl;
		else
			cout << '\t' << '\t';
	}

	// 计算哈夫曼编码所需的存储比特数
	int huffmanBits = calculateHuffmanBits(text, huffmanCodes);
	std::cout << "\n哈夫曼编码所需的存储比特数: " << huffmanBits << " bits" << std::endl;

	// 计算定长编码所需的存储比特数
	int fixedLengthBits = calculateFixedLengthBits(text);
	std::cout << "定长编码所需的存储比特数: " << fixedLengthBits << " bits" << std::endl;

	// 释放内存
	delete root;
}


void greedySelectorForHaffman()
{
	unordered_map<char, int>charFreq;
	string text;
	getHuffmanData(charFreq, text);
	int count = 1;
	for (const auto& pair : charFreq) {
		char c = pair.first;
		if (std::isprint(static_cast<unsigned char>(c))) { // 确保 c 是 unsigned char 类型
			std::cout << "'" << c << "' : " << pair.second;
		}
		else {
			std::cout << "\\x" << std::hex << static_cast<int>(static_cast<unsigned char>(c)) << " : " << std::dec << pair.second;
		}
	}
	cout << endl;

	buildHuffmanTree(charFreq, text);
}