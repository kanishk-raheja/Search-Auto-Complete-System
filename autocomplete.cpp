#include <bits/stdc++.h>
using namespace std;

/* ---------- TRIE NODE ---------- */
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    int freq;

    TrieNode() {
        isEnd = false;
        freq = 0;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

/* ---------- TRIE CLASS ---------- */
class Trie {
private:
    TrieNode* root;

    // DFS with early stopping (optimized)
    void dfs(
        TrieNode* node,
        string current,
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
        >& pq,
        int k
    ) {
        if (node->isEnd) {
            pq.push({node->freq, current});
            if ((int)pq.size() > k)
                pq.pop();
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                dfs(node->children[i],
                    current + char('a' + i),
                    pq, k);
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insertWord(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        curr->freq++;
    }

    vector<string> getSuggestions(const string& prefix, int k) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!curr->children[idx])
                return {};
            curr = curr->children[idx];
        }

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
        > pq;

        dfs(curr, prefix, pq, k);

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

/* ---------- MAIN ---------- */
int main() {
    Trie trie;

    vector<string> dictionary = {
        "app", "apple", "apply", "application",
        "bat", "ball", "banana",
        "app", "app"
    };

    for (const string& word : dictionary)
        trie.insertWord(word);

    string prefix;
    cout << "Enter search prefix: ";
    cin >> prefix;

    vector<string> suggestions = trie.getSuggestions(prefix, 5);

    cout << "\nAutocomplete Suggestions:\n";
    for (const string& word : suggestions)
        cout << word << endl;

    return 0;
}
