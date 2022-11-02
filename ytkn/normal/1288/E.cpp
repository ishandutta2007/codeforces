#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

//1-indexed
template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

int ans_max[300001];
int ans_min[300001];
int idx[600000];
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> m;
    bit<int> bt(n+m+2);
    for(int i = 1; i <= n; i++){
        int a;
        a = i;
        idx[a] = i+m;
        bt.add(idx[a], 1);
        ans_max[a] = i;
        ans_min[a] = i;
    }
    for(int i = 1; i <= m; i++){
        int b;
        cin >> b;
        ans_min[b] = 1;
        ans_max[b] = max(ans_max[b], bt.sum(idx[b]));
        // cout << bt.sum(idx[b]) << endl;
        bt.add(idx[b], -1);
        bt.add(m-i+1, 1);
        idx[b] = m-i+1;
    }
    for(int i = 1; i <= n; i++){
        ans_max[i] = max(ans_max[i], bt.sum(idx[i]));
    }
    for(int i = 1; i <= n; i++){
        cout << ans_min[i] << ' ' << ans_max[i] << endl;
    }
}