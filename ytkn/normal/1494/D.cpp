    #include <iostream>
    #include <algorithm>
    #include <iomanip>
    #include <vector>
    #include <queue>
    #include <set>
    #include <map>
    #include <numeric>
    #include <functional>
    #include <cassert>
     
    #define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
    #define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;
     
    template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
     
    using namespace std;
    typedef long long ll;
     
    struct UnionFind {
        vector<int> data;
        UnionFind(int size) : data(size, -1) {}
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
     
    int n;
    int a[500][500];
     
    void input(){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
    }
     
    int to_idx(int i, int j){
        if(i > j) swap(i, j);
        return n+i*n+j;
    }
     
    using P = pair<int, int>;
     
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << setprecision(10) << fixed;
        input();
        UnionFind uf(n*n);
        int max_sa = -1;
        for(int i = 0; i < n; i++){
            map<int, vector<int>> mp;
            for(int j = 0; j < n; j++){
                chmax(max_sa, a[i][j]);
                mp[a[i][j]].push_back(j);
            }
            for(auto [_, v] : mp){
                for(int j = 0; j+1 < v.size(); j++){
                    uf.unionSet(to_idx(i, v[j]), to_idx(i, v[j+1]));
                }
            }
        }
        vector<int> maxs;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == max_sa) maxs.push_back(to_idx(i, j));
            }
        }
        for(int i = 0; i+1 < maxs.size(); i++){
            uf.unionSet(maxs[i], maxs[i+1]);
        }
        // compress
        map<int, int> compress;
        {   
            for(int i = 0; i < n; i++) {
                compress[i] = i;
            }
            int cur = n;
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    int idx = to_idx(i, j);
                    if(uf.root(idx) == idx){
                        // debug_value(idx);
                        // debug_value(cur);
                        compress[idx] = cur;
                        cur++;
                    }
                }
            }
        }
        int m = compress.size();
        vector<int> sarary(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) sarary[i] = a[i][i];
                else{
                    int idx = to_idx(i, j);
                    if(uf.root(idx) == idx) sarary[compress[idx]] = a[i][j];
                }
            }
        }
        set<P> edges;
        for(int i = 0; i < n; i++){
            vector<P> vp;
            for(int j = 0; j < n; j++){
                if(i == j){
                    vp.push_back(P(a[i][i], compress[i]));
                }else{
                    int idx = to_idx(i, j);
                    vp.push_back(P(a[i][j], compress[uf.root(idx)]));
                }
            }
            sort(vp.begin(), vp.end());
            for(int j = 0; j+1 < vp.size(); j++){

                if(vp[j] != vp[j+1]) edges.insert(P(vp[j].second, vp[j+1].second));
            }
        }
        cout << m << endl;
        for(int i = 0; i < m; i++) cout << sarary[i] << ' ';
        cout << endl;
        // int max_sa = *max_element(sarary.begin(), sarary.end());
        for(int i = 0; i < m; i++){
            if(sarary[i] == max_sa) cout << i+1 << endl;
        }
        for(P p : edges) cout << p.first+1 << ' ' << p.second+1 << endl;
    }