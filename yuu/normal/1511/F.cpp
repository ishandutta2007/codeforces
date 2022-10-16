#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[8];

map<tuple<int, int>, int> mapped;
map<int, int> valid_map;
set<int> g[2000];
set<int> rg[2000];
bool is_end_state[10000];
int sz;

class AhoCorasick {
  public:
    class Node {
      public:
        int next[256];
        bool is_end;
        string s;
        Node(string str = "") {
            for (int i = 'a'; i <= 'z'; i++) next[i] = -1;
            is_end = false;
            s = str;
        }
    };
    vector<Node> nodes;

    AhoCorasick() { nodes.emplace_back(); }

    void Insert(const string& s) {
        int root = 0;
        for (auto&& c : s) {
            if (nodes[root].next[c] == -1) {
                nodes[root].next[c] = nodes.size();
                nodes.emplace_back(nodes[root].s + c);
            }
            root = nodes[root].next[c];
        }
        nodes[root].is_end = true;
    }

    void Make() {
        for (int i = 1; i < nodes.size(); i++) reverse(nodes[i].s.begin(), nodes[i].s.end());
        int id = 0;
        for (int i = 1; i < nodes.size(); i++) {
            for (int j = 1; j < nodes.size(); j++) {
                if ((nodes[i].s.find(nodes[j].s) == 0) || (nodes[j].s.find(nodes[i].s) == 0)) {
                    id++;
                    mapped[{i, j}] = id;
                }
            }
        }

        for (auto&& [value, id] : mapped) {
            auto&& [i, j] = value;
            for (int c = 'a'; c <= 'z'; c++) {
                vector<int> next_i;
                vector<int> next_j;
                next_i.push_back(nodes[i].next[c]);
                if (nodes[i].is_end) next_i.push_back(nodes[0].next[c]);
                next_j.push_back(nodes[j].next[c]);
                if (nodes[j].is_end) next_j.push_back(nodes[0].next[c]);
                for (auto&& ni : next_i)
                    for (auto&& nj : next_j) {
                        if ((ni == -1) || (nj == -1)) continue;
                        int nid = mapped[{ni, nj}];
                        assert(nid);
                        g[id].insert(nid);
                        rg[nid].insert(id);
                    }
            }
        }
    }

    bool is_end_state(int i, int j) { return nodes[i].is_end && nodes[j].is_end; }

    bool is_good_start(int i, int j) {
        for (int c = 'a'; c <= 'z'; c++) {
            if ((nodes[i].next[c] != -1) || (nodes[j].next[c] != -1)) return false;
        }
        return true;
    }
} aho;

constexpr int64_t base = 998'244'353;
constexpr int MAX_SIZE = 256;
class Matrix {
  public:
    int64_t f[MAX_SIZE][MAX_SIZE];

    Matrix() {
        memset(f, sizeof(f), 0);
        memset(f, 0, sizeof(f));
    }

    int64_t* operator[](const int& key) { return f[key]; }
    const int64_t* operator[](const int& key) const { return f[key]; }

    friend Matrix operator*(const Matrix& A, const Matrix& B) {
        Matrix res;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < sz; k++) {
                    (res[i][j] += A[i][k] * B[k][j]) %= base;
                }
            }
        }
        return res;
    }

    Matrix RaiseToPower(int power) {
        Matrix p = *this;
        while (power % 2 == 0) {
            p = p * p;
            power /= 2;
        }
        Matrix res = p;
        p = p * p;
        power /= 2;
        while (power) {
            if (power % 2) res = res * p;
            p = p * p;
            power /= 2;
        }
        return res;
    }
};

Matrix start, trans;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        aho.Insert(s[i]);
    }
    aho.Make();

    // remove all vertex that don't have in or out edge
    queue<int> q;
    for (int i = 1; i <= mapped.size(); i++)
        if (g[i].empty() || rg[i].empty()) {
            q.push(i);
        }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto&& x : g[u]) {
            if (rg[x].empty() || g[x].empty()) continue;
            rg[x].erase(u);
            if (rg[x].empty()) {
                q.push(x);
            }
        }
        g[u].clear();
        for (auto&& x : rg[u]) {
            if (g[x].empty() || rg[x].empty()) continue;
            g[x].erase(u);
            if (g[x].empty()) {
                q.push(x);
            }
        }
        rg[u].clear();
    }

    for (int i = 1; i <= mapped.size(); i++)
        if (!g[i].empty()) {
            valid_map[i] = sz;
            sz++;
        }

    for (auto&& [value, id] : mapped) {
        if (g[id].empty()) continue;
        auto&& [i, j] = value;
        is_end_state[valid_map[id]] = aho.is_end_state(i, j);
    }
    for (auto&& [value, id] : mapped) {
        if (g[id].empty()) continue;
        auto&& [i, j] = value;
        if (aho.is_good_start(i, j)) {
            start[0][valid_map[id]] = 1;
            break;
        }
    }
    if (sz == 0) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= mapped.size(); i++) {
        if (g[i].empty()) continue;
        for (int j : g[i]) {
            trans[valid_map[i]][valid_map[j]] = 1;
        }
    }

    assert(valid_map.size() == sz);
    trans = trans.RaiseToPower(m);
    int64_t ans = 0;

    start = start * trans;
    for (int i = 0; i < sz; i++) {
        if (is_end_state[i]) {
            (ans += start[0][i]) %= base;
        }
    }

    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}