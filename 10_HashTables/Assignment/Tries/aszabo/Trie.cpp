#include "Trie.h"
#include <vector>
#include <algorithm>
#include <list>

// trie_counter should be incremented by one after 
// each word is checked in the 'filter' function.
int trie_counter = 0;

TrieNode::TrieNode() {}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    deleteTrie(root);
}

void Trie::deleteTrie(TrieNode* node) {
    if (!node) return;

    for (auto &child : node->children) {
        deleteTrie(child.second);
    }

    node->children.clear();
    delete node;
}

unsigned int Trie::countLeaves(TrieNode* node) const {
    if (!node) return 0;

    if (node->children.empty()) return 1;

    unsigned int counter = 0;
    for (auto &child : node->children) {
        counter += countLeaves(child.second);
    }

    return counter;
}

unsigned int Trie::size() const {
    if (root->children.empty()) return 0;
    return countLeaves(root);
}

bool Trie::insert(const std::string &word) {
    if (root == nullptr) return false;
    if (word.length() != 5) return false;

    TrieNode* current = root;
    bool inserted = false;

    for (char letter : word) {
        if (current->children.find(letter) == current->children.end()) {
            current->children[letter] = new TrieNode();
            inserted = true;
        }
        current = current->children[letter];
    }

    return inserted;
}

std::string Trie::getFirstWord() {
    if (!root) return "";

    TrieNode* current = root;
    std::string word = "";

    for (unsigned int i = 0; i < 5; ++i) {
        word += current->children.begin()->first;
        current = current->children.begin()->second;
    }

    return word;
}

std::list<std::string> Trie::getAllWords() const {
    std::list<std::string> words;
    std::string currentWord = "";
    getWordsRecursively(root, currentWord, words);
    return words;
}

void Trie::getWordsRecursively(TrieNode *node, std::string currentWord, std::list<std::string> &words) const {
    if (currentWord.size() == 5) {
        words.push_back(currentWord);
        return;
    }

    for (auto& child : node->children) {
        getWordsRecursively(child.second, currentWord + child.first, words);
    }
}

// TODO
bool Trie::filter(const string& guess, const string& pattern) {}

// TODO
void Trie::filterRecursively(TrieNode* node, std::string currentWord, const string& guess, const string& pattern) {}


void Trie::print() {
    if (!root) {
        cout << "EMPTY TRIE" << endl;
        return;
    }

    std::list<string> allWords = getAllWords();
    for (string word : allWords) {
        cout << word << endl;
    }
}
