#include <bits/stdc++.h>
using namespace std;

int n, m, p, a[310][310];
vector <pair <int, pair <int, int> > > tr[100010];
#define mp make_pair
#define dist(x,y,X,Y) abs(x-X)+abs(y-Y)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      tr[a[i][j]].push_back(mp(1000000000,mp(i,j)));
    }
  }
  for (int i = 0; i < tr[1].size(); i++) {
    tr[1][i].first = dist(0, 0, tr[1][i].second.first, tr[1][i].second.second);
  }
  for (int i = 2; i <= p; i++) {
    sort(tr[i - 1].begin(), tr[i - 1].end());
    for (int j = 0; j < min((int)tr[i - 1].size(), n + m-1); j++) {
      for (int k = 0; k < tr[i].size(); k++) {
        tr[i][k].first = min(tr[i][k].first, tr[i - 1][j].first + 
          dist(tr[i - 1][j].second.first, tr[i - 1][j].second.second, tr[i][k].second.first, tr[i][k].second.second));
      }
    }
  }
  sort(tr[p].begin(), tr[p].end());
  cout << tr[p][0].first << endl;
  return 0;
}