#include <bits/stdc++.h>
using namespace std;

const int N = 10006;

bool vis[N];
int ans[N];

int Q(int x) {
  cout << "? " << x << endl;
  int ret; cin >> ret;
  return ret;
}

void show_ans(int n) {
  cout << "!";
  for (int i = 1; i <= n; ++i) {
    cout << " " << ans[i];
  }
  cout << endl;
}

void go() {
  int n; cin >> n;
  for (int i = 0; i <= n + 1; ++i) {
    vis[i] = false;
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    int _ = Q(i);
    vector<int> v;
    v.push_back(_);
    vis[_] = true;
    while (true) {
      int tmp = Q(i);
      v.push_back(tmp);
      if (vis[tmp]) break;
      vis[tmp] = true;
    }
    for (int x = 0; x < (int)v.size() - 1; ++x) {
      ans[v[x]] = v[x + 1];
    }
  }
  show_ans(n);
}

int main () {
  int T; cin >> T;
  while (T--) {
    go();
  }
}