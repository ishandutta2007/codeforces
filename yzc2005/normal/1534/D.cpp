#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, d[N];
set<pair<int, int>> ans;
vector<int> v[2];
//void solve(int u) {
//  vis[u] = v[u] = true;
//  cout << "? " << u << endl;
//  vector<vector<int>> v(n);
//  for (int i = 1; i <= n; ++i) {
//    cin >> d[i];
//    if (!::v[i]) v[d[i]].emplace_back(i);
//  }
//  for (int i = 1, last = u; i < n; ++i) {
//    if (v[i].empty()) break;
//    for (auto x : v[i]) vis[x] = true, ans.emplace_back(last, x);
//    if (v[i].size() > 1) break;
//    else last = v[i][0];
//    vis[last] = true;
//  }
//}
void solve(vector<int> vec) {
  for (auto x : vec) {
    cout << "? " << x << endl;
    for (int i = 1; i <= n; ++i) 
      if (cin >> d[i], d[i] == 1) {
        int u, v; tie(u, v) = minmax(x, i);
        ans.emplace(u, v);
      } 
  }
}
int main() {
  cin >> n; 
  cout << "? 1" << endl; cin >> d[1];
  for (int i = 2; i <= n; ++i) cin >> d[i], v[d[i] & 1].emplace_back(i);
  for (int i = 2; i <= n; ++i) if (d[i] == 1) ans.emplace(1, i);
  if (v[0].size() < v[1].size()) solve(v[0]);
  else solve(v[1]);
  cout << "!" << endl; for (auto p : ans) cout << p.first << " " << p.second << endl;
  return 0;
}