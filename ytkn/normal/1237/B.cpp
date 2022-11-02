#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

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

int n;
int a[200000];
int idx[200000];
int b[200000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        idx[a[i]] = i+1;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i]--;
    }
    bit<int> bt(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = bt.sum(idx[b[i]]);
        if(sum != idx[b[i]]-1) ans++;
        bt.add(idx[b[i]], 1);
    }
    cout << ans << endl;
}