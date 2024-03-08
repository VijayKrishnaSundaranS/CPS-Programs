#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// A Huffman tree node
struct HuffmanNode {
    char data; // Character
    unsigned frequency; // Frequency of the character
    HuffmanNode *left, *right; // Left and right child pointers

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->frequency > r->frequency;
    }
};

// Function to print Huffman codes from the root of Huffman Tree
void printCodes(HuffmanNode* root, string str, unordered_map<char, string>& codes) {
    if (!root)
        return;

    if (root->data != '$') // If it's not an internal node
        codes[root->data] = str;

    printCodes(root->left, str + "0", codes);
    printCodes(root->right, str + "1", codes);
}

// Function to build Huffman Tree and generate codes
unordered_map<char, string> buildHuffmanTree(string text) {
    unordered_map<char, unsigned> frequencyMap;
    for (char c : text)
        frequencyMap[c]++;

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (const auto& pair : frequencyMap)
        pq.push(new HuffmanNode(pair.first, pair.second));

    while (pq.size() != 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    HuffmanNode* root = pq.top();
    unordered_map<char, string> codes;
    printCodes(root, "", codes);

    return codes;
}

int main() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    unordered_map<char, string> codes = buildHuffmanTree(text);

    cout << "Huffman Codes:" << endl;
    for (const auto& pair : codes)
        cout << pair.first << " : " << pair.second << endl;

    return 0;
}