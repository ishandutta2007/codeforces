#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    int m = 1<<n;
    string s; cin >> s;
    vector<int> a(m);
    auto inv = [&](int x){ return m-x-2; };
    
    auto par = [&](int x){
        if(x == m-2) return -1;
        int y = inv(x);
        int z = (y-1)/2;
        return inv(z);
    };
    auto left_ch = [&](int x){
        int y = inv(x);
        int z = 2*(y+1);
        return inv(z);
    };
    auto right_ch = [&](int x){
        int y = inv(x);
        int z = 2*y+1;
        return inv(z);
    };

    for(int i = 0; i < m-1; i++){
        if(left_ch(i) < 0){
            if(s[i] == '?') a[i] = 2;
            else a[i] = 1;
        }else{
            if(s[i] == '?') a[i] = a[left_ch(i)] + a[right_ch(i)];
            else if(s[i] == '0') a[i] = a[left_ch(i)];
            else a[i] = a[right_ch(i)];
        }
    }
    // for(int i = 0; i < m-1; i++) cout << i << ' ' << par(i) << ' ' << left_ch(i) << ' ' << right_ch(i) << endl;
    int q; cin >> q;
    while(q--){
        int i; char c; cin >> i >> c; i--;
        s[i] = c;
        while(i != -1){
            if(left_ch(i) < 0){
                if(s[i] == '?') a[i] = 2;
                else a[i] = 1;
            }else{
                if(s[i] == '?') a[i] = a[left_ch(i)] + a[right_ch(i)];
                else if(s[i] == '0') a[i] = a[left_ch(i)];
                else a[i] = a[right_ch(i)];
            }
            i = par(i);
        }
        cout << a[m-2] << endl;
    }
}