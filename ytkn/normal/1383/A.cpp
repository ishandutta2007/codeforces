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
     
    bool g[20][20];
     
    void solve(){
        int n;
        string a, b;
        cin >> n >> a >> b;
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++){
                g[i][j] = false;
            }
        }
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                cout << -1 << endl;
                return;
            }
            if(a[i] < b[i]){
                g[a[i]-'a'][b[i]-'a'] = true;
            }
        }
        UnionFind uf(20);
        int ans = 0;
        for(int i = 1; i < 20; i++){
            for(int j = 0; i+j < 20; j++){
                if(g[j][i+j]){
                    if(!uf.findSet(j, i+j)){
                        ans++;
                        uf.unionSet(j, i+j);
                    }
                }
            }
        }
        cout << ans << endl;
    }
     
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << setprecision(10) << fixed;
        int t; cin >> t;
        for(int i = 0; i < t; i++)solve();
    }