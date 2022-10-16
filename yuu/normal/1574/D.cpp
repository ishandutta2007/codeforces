#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> c[10];
set<vector<int>> banned;
set<vector<int>> done;
class State {
public:
  vector<int> f;
  int strength;

  explicit State(vector<int> pos) noexcept : f(pos), strength(0) {
    for (int i = 0; i < n; i++) {
      strength += c[i][f[i]];
    }
  }

  bool is_banned() const { return (banned.find(f) != banned.end()); }

  friend bool operator<(const State &s, const State &t) {
    return s.strength < t.strength;
  }
};

priority_queue<State> q;
void solve() {
  cin >> n;
  for (int i = 0, m; i < n; i++) {
    cin >> m;
    c[i].resize(m);
    for (auto &x : c[i])
      cin >> x;
  }
  cin >> m;
  vector<int> temp;
  done.insert(temp);
  temp.resize(n);
  for (int i = 0; i < m; i++) {
    for (auto &x : temp) {
      cin >> x;
      x--;
    }
    banned.insert(temp);
  }
  for (int i = 0; i < n; i++)
    temp[i] = c[i].size() - 1;
  q.push(State(temp));
  while (true) {
    if (q.top().is_banned()) {
      temp = q.top().f;
      q.pop();
      for (auto &x : temp) {
        if (x) {
          x--;
          if (done.find(temp) == done.end()) {
            done.insert(temp);
            q.push(State(temp));
          }
          x++;
        }
      }
    } else {
      cerr << q.top().strength << '\n';
      for (auto &&x : q.top().f)
        cout << x + 1 << ' ';
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}