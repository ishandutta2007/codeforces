#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int cnt[200000][26];

void clear(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            cnt[i][j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        UnionFind uf(n);
        clear(n);
        for(int i = 0; i < n; i++){
            int p = n-i-1;
            int q = i+k;
            uf.unionSet(i, p);
            if(q < n) uf.unionSet(i, q);
        }
        for(int i = 0; i < n; i++){
            int r = uf.root(i);
            int c = s[i]-'a';
            cnt[r][c]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int all = 0;
            int mx = 0;
            for(int j = 0; j < 26; j++){
                mx = max(mx, cnt[i][j]);
                all += cnt[i][j];
            }
            ans += (all-mx);
        }
        cout << ans << endl;
    }
}