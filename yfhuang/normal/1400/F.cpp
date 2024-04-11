#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

template<char MIN_CHAR = 'a', int ALPHABET = 26>
struct aho_corasick {
    struct node {
        // suff = the index of the node of the longest strict suffix of the current node that's also in the tree.
        //   Also see "blue arcs" on Wikipedia: https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm
        // dict = the index of the node of the longest strict suffix of the current node that's in the word list.
        //   Also see "green arcs" on Wikipedia.
        // depth = normal trie depth (root is 0). Can be removed to save memory.
        // word_index = the index of the *first* word ending at this node. -1 if none.
        // word_count = the total number of words ending at this node. Used in count_total_matches().
        // link = the trie connections and/or suffix connections from this node.
        int suff = -1, dict = -1, depth = 0;
        int word_index = -1, word_count = 0;
        int link[ALPHABET];
 
        node() {
            fill(link, link + ALPHABET, -1);
        }
 
        int& operator[](char c) {
            return link[c - MIN_CHAR];
        }
    };
 
    vector<node> nodes;
    int W;
    vector<int> word_location;
    vector<int> word_indices_by_depth;
    vector<int> defer;
 
    aho_corasick(const vector<string> &words = {}) {
        if (!words.empty())
            build(words);
    }
 
    // Builds the adj list based on suffix parents. Often we want to perform DP and/or queries on this tree.
    vector<vector<int>> build_suffix_adj() const {
        vector<vector<int>> adj(nodes.size());
 
        for (int i = 1; i < int(nodes.size()); i++)
            adj[nodes[i].suff].push_back(i);
 
        return adj;
    }
 
    int get_or_add_child(int current, char c) {
        if (nodes[current][c] >= 0)
            return nodes[current][c];
 
        int index = int(nodes.size());
        nodes[current][c] = index;
        nodes.emplace_back();
        nodes.back().depth = nodes[current].depth + 1;
        return index;
    }
 
    int add_word(const string &word, int word_index) {
        assert(!nodes.empty());
        int current = 0;
 
        for (char c : word)
            current = get_or_add_child(current, c);
 
        if (nodes[current].word_index < 0)
            nodes[current].word_index = word_index;
 
        nodes[current].word_count++;
        return current;
    }
 
    // Returns where in the trie we should end up after starting at `location` and adding char `c`. Runs in O(1).
    int get_suffix_link(int location, char c) const {
        if (location >= 0)
            location = nodes[location].link[c - MIN_CHAR];
 
        return max(location, 0);
    }
 
    void build(const vector<string> &words) {
        nodes = {node()};
        W = int(words.size());
        word_location.resize(W);
        defer.resize(W);
        int max_depth = 0;
 
        for (int i = 0; i < W; i++) {
            word_location[i] = add_word(words[i], i);
            max_depth = max(max_depth, int(words[i].size()));
            defer[i] = nodes[word_location[i]].word_index;
        }
 
        // Create a list of word indices in decreasing order of depth, in linear time via counting sort.
        word_indices_by_depth.resize(W);
        vector<int> depth_freq(max_depth + 1, 0);
 
        for (int i = 0; i < W; i++)
            depth_freq[words[i].size()]++;
 
        for (int i = max_depth - 1; i >= 0; i--)
            depth_freq[i] += depth_freq[i + 1];
 
        for (int i = 0; i < W; i++)
            word_indices_by_depth[--depth_freq[words[i].size()]] = i;
 
        // Solve suffix parents by traversing in order of depth (BFS order).
        vector<int> q = {0};
 
        for (int i = 0; i < int(q.size()); i++) {
            int current = q[i];
 
            for (char c = MIN_CHAR; c < MIN_CHAR + ALPHABET; c++) {
                int &index = nodes[current][c];
 
                if (index >= 0) {
                    // Find index's suffix parent by traversing suffix parents of current until one of them has a child c.
                    int suffix_parent = get_suffix_link(nodes[current].suff, c);
                    nodes[index].suff = suffix_parent;
                    nodes[index].word_count += nodes[suffix_parent].word_count;
                    nodes[index].dict = nodes[suffix_parent].word_index < 0 ? nodes[suffix_parent].dict : suffix_parent;
                    q.push_back(index);
                } else {
                    index = get_suffix_link(nodes[current].suff, c);
                }
            }
        }
    }
 
    // Counts the number of matches of each word in O(text length + num words).
    vector<int> count_matches(const string &text) const {
        vector<int> matches(W, 0);
        int current = 0;
 
        for (char c : text) {
            current = get_suffix_link(current, c);
            int dict_node = nodes[current].word_index < 0 ? nodes[current].dict : current;
 
            if (dict_node >= 0)
                matches[nodes[dict_node].word_index]++;
        }
 
        // Iterate in decreasing order of depth.
        for (int word_index : word_indices_by_depth) {
            int location = word_location[word_index];
            int dict_node = nodes[location].dict;
 
            if (dict_node >= 0)
                matches[nodes[dict_node].word_index] += matches[word_index];
        }
 
        for (int i = 0; i < W; i++)
            matches[i] = matches[defer[i]];
 
        return matches;
    }
 
    // Counts the number of matches over all words at each ending position in `text` in O(text length).
    vector<int> count_matches_by_position(const string &text) const {
        vector<int> matches(text.size());
        int current = 0;
 
        for (int i = 0; i < int(text.size()); i++) {
            current = get_suffix_link(current, text[i]);
            matches[i] = nodes[current].word_count;
        }
 
        return matches;
    }
 
    // Counts the total number of matches of all words within `text` in O(text length).
    int64_t count_total_matches(const string &text) const {
        int64_t matches = 0;
        int current = 0;
 
        for (char c : text) {
            current = get_suffix_link(current, c);
            matches += nodes[current].word_count;
        }
 
        return matches;
    }
};

string s;
int x;

int check(string s){
    int m = s.length();
    int sum = 0;
    for(int l = 0;l < m;l++){
        sum += s[l] - '0';
    }
    if(sum > x)
        return -1;
    for(int l = 0;l < m;l++){
        int sum = 0;
        for(int r = l;r < m;r++){
            sum += s[r] - '0';
        }
        if(sum < x and x % sum == 0){
            return -1;
        }
    }
    if(sum == x)
        return 1;
    else
        return 0;
}

vector<string> prime;

void generate(string s){
    int ret = check(s);
    if(ret == -1)
        return;
    if(ret == 0)
        for(char ch = '1';ch <= '9';ch++){
            generate(s + ch);
        }
    else
        prime.push_back(s);
}

aho_corasick<'1', 9> AC;

int dp[2][10000];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s >> x;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    generate("");
    AC.build(prime);
    int ST = int(AC.nodes.size());
    for(int i = 0;i < s.length();i++){
        int cur = i & 1;
        int nxt = cur ^ 1;
        memset(dp[nxt], 0x3f, sizeof(dp[nxt]));
        for(int state = 0;state < ST;state++){
            dp[nxt][state] = min(dp[nxt][state], dp[cur][state] + 1);
            int trans = AC.get_suffix_link(state, s[i]);
            if(AC.nodes[trans].word_index < 0){
                dp[nxt][trans] = min(dp[nxt][trans], dp[cur][state]);
            }
        }
    }
    int ans = 1e9;
    for(int i = 0;i < ST;i++){
        ans = min(ans, dp[s.length() & 1][i]);
    }
    cout << ans << endl;
    return 0;
}