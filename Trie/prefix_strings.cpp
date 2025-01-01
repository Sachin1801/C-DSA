#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    char ch;
    unordered_map<char, Node*> m;
    bool isTerminal;
    int cnt;

public:
    Node(char d) {
        ch = d;
        isTerminal = false; // Corrected "False" to "false"
        cnt = 0;            // Fixed initialization of `cnt`
    }

    friend class Trie;
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node('\0');
    }

    void insert(string word) {
        Node* temp = root;
        for (auto ch : word) {
            if (temp->m.count(ch) == 0) {
                Node* n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
            temp->cnt++;
        }
        temp->isTerminal = true;
    }

    // Function to find words with the given prefix
    void findWordsWithPrefix(Node* node, vector<string>& result, string currentWord) {
        if (node->isTerminal) {
            result.push_back(currentWord);
        }
        for (auto& [key, child] : node->m) {
            findWordsWithPrefix(child, result, currentWord + key);
        }
    }

    vector<string> getWordsWithPrefix(string prefix) {
        Node* temp = root;
        for (char ch : prefix) {
            if (temp->m.count(ch) == 0) {
                return {}; // Prefix not found
            }
            temp = temp->m[ch];
        }
        vector<string> result;
        findWordsWithPrefix(temp, result, prefix);
        return result;
    }
};

vector<string> findPrefixStrings(vector<string> words, string prefix) {
    Trie t;

    // Insert all words into the Trie
    for (auto word : words) {
        t.insert(word);
    }

    // Get all words with the given prefix
    vector<string> ans = t.getWordsWithPrefix(prefix);

    // Sort the result lexicographically
    sort(ans.begin(), ans.end());
    return ans;
}
