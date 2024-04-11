#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> vi;
const int MAXN = 300000 + 10;

struct RemoveNext {
  vector<int> data;
 
  void init(int n) {
    data.assign(n, -1);
  }
 
  int get(int i) {
    int a = i, b, c = i;
    while((b = data[a]) >= 0) a = b;
    while((b = data[c]) >= 0) data[c] = a, c = b;
    return a;
  }
 
  void remove(int i) {
    data[i] = i + 1;
  }
};

vector<int> G[MAXN];
int n, m, k;

int complementBFS(int src, const vi g[MAXN], vector<int> &prev) {
  RemoveNext undiscovered;
  undiscovered.init(n + 1);
  vector<bool> mark(n, false);
  vector<int> q;
 
  prev.assign(n, -1);
  q.push_back(src);
  undiscovered.remove(src);
  for(int h = 0; h != q.size(); ) {
    int u = q[h ++];
    for(int v : g[u]) mark[v] = true;
    for(int i = undiscovered.get(0); i < n; i = undiscovered.get(i + 1)) {
      if(!mark[i]) {
        undiscovered.remove(i);
        q.push_back(i);
        prev[i] = u;
      } else {
        mark[i] = false;
      }
    }
  }
  return q.size();
}

set<int> S;
int dsu[MAXN];

int get(int x) {
  if (x != dsu[x]) dsu[x] = get(dsu[x]);
  return dsu[x];
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int a, b; scanf("%d%d", &a, &b);
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
    if (a == 0) S.insert(b);
    if (b == 0) S.insert(a);
  }
  vector<int> pv;
  int now = complementBFS(0, G, pv);
  //cout << now << endl;
  if (now != n) {
    puts("impossible");
    return 0;
  }
  int R = 0;
  for (int i = 1; i < n; ++i) R += pv[i] == 0;
  RemoveNext undiscovered;
  undiscovered.init(n + 1);
  vector<bool> mark(n, false);
  for (int i = 1; i < n; ++i) {
    G[0].push_back(i);
    G[i].push_back(0);
  }
  pv.assign(n, -1);
  for (int i = 0; i < n; ++i) if (undiscovered.data[i] == -1) {
    vector<int> q;
    q.push_back(i);
    undiscovered.remove(i);
    for(int h = 0; h != q.size(); ) {
      int u = q[h ++];
      for(int v : G[u]) mark[v] = true;
      for(int i = undiscovered.get(0); i < n; i = undiscovered.get(i + 1)) {
        if(!mark[i]) {
          undiscovered.remove(i);
          q.push_back(i);
          pv[i] = u;
        } else {
          mark[i] = false;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) dsu[i] = i;
  for (int i = 0; i < n; ++i) if (pv[i] != -1) {
    int a = get(i), b = get(pv[i]);
    dsu[a] = b;
  }
  int L = 0;
  for (int i = 1; i < n; ++i) if (!S.count(i)) {
    int a = get(0), b = get(i);
    if (a != b) dsu[b] = a, ++L;
  }
  //cout << L << " " << R << endl;
  if (L <= k && k <= R) puts("possible");
  else puts("impossible");
  return 0;
}