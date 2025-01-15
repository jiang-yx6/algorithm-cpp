#pragma once
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cctype> 
#include <queue>
#include <string>
using namespace std;
struct HuffmanNode {
	char data;
	int freq;
	HuffmanNode* left;
	HuffmanNode* right;

	HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct Compare {
	bool operator()(HuffmanNode* l, HuffmanNode* r) {
		return l->freq > r->freq;
	}
};


void greedySelectorForHaffman();

void getHuffmanData(unordered_map<char, int>& data, string& text);

void generateCodes(HuffmanNode* root, string str, std::unordered_map<char, std::string>& huffmanCode);

void buildHuffmanTree(const std::unordered_map<char, int>& charFreq, const string& text);

int calculateFixedLengthBits(const string& text);

int calculateHuffmanBits(const string& text, const std::unordered_map<char, std::string>& huffmanCode);

#endif 