#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  string line;
  int res = 0;

  struct Node {
    Node* to[26];
    Node* p = nullptr;
    int cnt = 0;
    bool term = false;

    Node() {
      fill(to, to + 26, nullptr);
    }

    void add_leaf(int by) {
      to[by] = new Node();
      to[by]->p = this;
    }

    void mark(bool is_term) {
      if (is_term) {
        term = true;
      }
      ++cnt;
      if (p) {
        p->mark(false);
      }
    }
  };

  Node* root = new Node();
  Node* u = root;
  while (getline(cin, line)) {
    line += '\n';
    res += (int) line.size();
    int first_unique = -1;
    int last_term = -1;
    int h = 0;
    for (char ch : line) {
      if (!islower(ch)) {
        if (!u->term) {
          u->mark(true);
        }
        if (last_term != -1) {
          res -= max(0, last_term - first_unique - 1);
        } else {
        }
        u = root;
        last_term = first_unique = -1;
        h = 0;
      } else {
        int c = ch - 'a';
        if (!u->to[c]) {
          u->add_leaf(c);
        }
        u = u->to[c];
        ++h;
        if (first_unique == -1) {
          if (u->cnt == 1) {
            first_unique = h;
          }
        }
        if (first_unique != -1 && u->term) {
          last_term = h;
        }
      }
    }
  }
  cout << res << '\n';
}