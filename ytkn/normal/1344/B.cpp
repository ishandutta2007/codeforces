#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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

int H, W;

int dh[4] = {0, 0, -1, 1};
int dw[4] = {-1, 1, 0, 0};

bool is_in_field(int i, int j){
    return i >= 0 && i < H && j >= 0 && j < W;
}

char c[1000][1000];

void input(){
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> c[i][j];
        }
    }
}

int to_idx(int i, int j){
    return i*W+j;
}

void solve(){
    vector<vector<int>> vh(H);
    vector<vector<int>> vw(W);
    UnionFind uf(H*W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(c[i][j] == '#'){
                if(vh[i].size() > 0){
                    int sz = vh[i].size();
                    if(vh[i][sz-1] != j-1){
                        cout << -1 << endl;
                        return;
                    }
                }
                if(vw[j].size() > 0){
                    int sz = vw[j].size();
                    if(vw[j][sz-1] != i-1){
                        cout << -1 << endl;
                        return;
                    }
                }
                vh[i].push_back(j);
                vw[j].push_back(i);
                for(int k = 0; k < 4; k++){
                    int i_to = i + dh[k];
                    int j_to = j + dw[k];
                    if(is_in_field(i_to, j_to) && c[i_to][j_to] == '#'){
                        uf.unionSet(to_idx(i, j), to_idx(i_to, j_to));
                    }
                }
            }
        }
    }
    int ans = 0;
    vector<bool> okh(H, false);
    vector<bool> okw(W, false);
    for(int i = 0; i < H; i++){
        if(vh[i].size() != 0) okh[i] = true;
    }
    for(int j = 0; j < W; j++){
        if(vw[j].size() != 0) okw[j] = true;
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(vh[i].size() == 0 && vw[j].size() == 0){
                okh[i] = true;
                okw[j] = true;
            }
        }
    }
    for(int i = 0; i < H; i++){
        if(!okh[i]){
            cout << -1 << endl;
            return;
        }
    }
    for(int j = 0; j < W; j++){
        if(!okw[j]){
            cout << -1 << endl;
            return;
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int idx = to_idx(i, j);
            if(c[i][j] == '#' && uf.root(idx) == idx){
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}