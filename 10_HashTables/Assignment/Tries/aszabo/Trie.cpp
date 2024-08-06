#include "Trie.h"

// trie_counter should be incremented by one after 
// each word is checked in the 'filter' function.
int trie_counter = 0;

TrieNode::TrieNode() {}

Trie::Trie() {}

Trie::~Trie() {}

void Trie::deleteTrie(TrieNode* node) {}

unsigned int Trie::countLeaves(TrieNode* node) const {}

unsigned int Trie::size() const {}

bool Trie::insert(const std::string &word) {}

std::string Trie::getFirstWord() {}

std::list<std::string> Trie::getAllWords() const {
    std::list<std::string> words;
    std::string currentWord = "";
    getWordsRecursively(root, currentWord, words);
    return words;
}

void Trie::getWordsRecursively(TrieNode *node, std::string currentWord, std::list<std::string> &words) const {
    if (currentWord.size() == 5) {
        words.push_back(currentWord);
    }

    for (auto& child : node->children) {
        getWordsRecursively(child.second, currentWord + child.first, words);
    }
}

bool Trie::filter(const std::string &guess, const std::string &pattern) {}

void Trie::filterRecursively(TrieNode* node, std::string currentWord, const std::string &guess, const std::string &pattern) {}

void Trie::print() {}