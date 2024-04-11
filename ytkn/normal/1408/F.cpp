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

vector<int> x, y;

void make_same(int l, int r){
    if(r-l == 1){
        return;
    }
    int c = (l+r)/2;
    make_same(l, c);
    make_same(c, r);
    for(int i = 0; i < c-l; i++){
        x.push_back(l+i);
        y.push_back(c+i);
    }
}

int msb(int n){
    for(int i = 20; i >= 0; i--){
        if(n&(1<<i)) return i;
    }
}

int lsb(int n){
    for(int i = 0; i <= 20; i++){
        if(n&(1<<i)) return i;
    }
}

void simulate(int n){
    auto f = [&](int x, int y){
        return (x*521+y)%10000;
    };
    vector<int> a(n+1);
    for(int i = 0; i <= n; i++) a[i] = i;
    for(int i = 0; i < x.size(); i++){
        int m = f(a[x[i]], a[y[i]]);
        a[x[i]] = m;
        a[y[i]] = m;
    }
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    int cur = 0;
    int ms = msb(n);
    int ls = lsb(n);
    for(int i = 0; i <= ms; i++){
        if(n&(1<<i)){
            make_same(cur+1, cur+(1<<i)+1);
            cur += (1<<i);
        }
    }
    // int cur = 0;
    vector<int> v, u;
    for(int l = n-(1<<ms)+1; l <= n; l++) v.push_back(l);
    for(int l = 1; l <= (1<<ls); l++) u.push_back(l);
    cur = 1<<ls;
    for(int i = ls; i < ms; i++){
        if(n&(1<<i) && i != ls){
            vector<int> to_add;
            for(int j = 0; j < u.size(); j++){
                x.push_back(u[j]);
                y.push_back(cur+j+1);
                to_add.push_back(cur+j+1);
            }
            for(int t : to_add) u.push_back(t);
            cur += (1<<i);
        }else{
            vector<int> to_add;
            for(int j = 0; j < u.size(); j++){
                int t = v[(int)v.size()-1];
                v.pop_back();
                x.push_back(t);
                y.push_back(u[j]);
                to_add.push_back(t);
            }
            for(int t : to_add) u.push_back(t);
        }
    }
    
    // simulate(n);
    cout << x.size() << endl;
    for(int i = 0; i < (int) x.size(); i++) cout << x[i] << ' ' << y[i] << endl;
}