#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Trie {
    struct TrieNode {
        bool isWordEnd;
        char data;
        TrieNode* children[26];
        TrieNode() {
            isWordEnd = false;
            data = 0;
            memset(children, 0, sizeof(void*)*26);
        }
        TrieNode(char c) {
            isWordEnd = false;
            data = c;
            memset(children, 0, sizeof(void*)*26);
        }
    };
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->children[word[i]-'a'] == nullptr) {
                p->children[word[i]-'a'] = new TrieNode(word[i]-'a');
            }
            p = p->children[word[i]-'a'];
        }
        p->isWordEnd = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->children[word[i]-'a'] == nullptr) {
                return false;
            }
            p = p->children[word[i]-'a'];
        }
        if (p->isWordEnd)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (p->children[prefix[i]-'a'] == nullptr) {
                return false;
            }
            p = p->children[prefix[i]-'a'];
        }
        return true;
    }
};

int main() {
    Trie trie = Trie();
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // returns true
    cout << trie.search("app") << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");
    cout << trie.search("app") << endl;     // returns true
    return 0;
}