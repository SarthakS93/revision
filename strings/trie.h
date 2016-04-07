#ifndef TRIE_H
#define TRIE_H
class Trie {
    TrieNode* root;
    int numWords;

    public:
    Trie() {
        root = new TrieNode('\0');
        numWords = 0;
    }

    int size {
        return numWords;
    }

    private:
    void addWord(char* word, TrieNode* node) {
        if(word[0] == '\0') {
            node->isTermianl = true;
            return;
        }

        char currentChar = word[0];
        TrieNode* child = NULL;

        if(node->children.find(currentChar) == node->children.end()) {
            child = new TrieNode(currentChar);
            node->children[currentChar] = child;
        }
        else {
            child = node->children.find(currentChar)->second;
        }
        addWord(word + 1, child);        
    }

    public:
    void addWord(char* word) {
        if(containsWord(word))
            return;
        addWord(word, root);
        numWords++;
    }


};
