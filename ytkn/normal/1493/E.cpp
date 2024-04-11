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
#include <bitset>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

string add_one(string s){
    int n = s.size();
    vector<int> v;
    for(char c: s) v.push_back(c-'0');
    reverse(v.begin(), v.end());
    vector<int> u;
    int carry = 1;
    for(int x: v){
        if(x == 1 && carry == 1){
            u.push_back(0);
        }else{
            u.push_back(x+carry);
            carry = 0;
        }
    }
    if(carry == 1) u.push_back(1);
    reverse(u.begin(), u.end());
    string t;
    for(int x: u) t += '0'+x;
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    string l, r; cin >> l >> r;
    if(l[0] != r[0]){
        for(int i = 0; i < n; i++) cout << 1;
        cout << endl;
        return 0;
    }
    if(r.back() == '1'){
        cout << r << endl;
        return 0;
    }
    string rr = add_one(add_one(l));
    string r_ = r;
    while(r_.size() < rr.size()) r_ = "0"+r_;
    if(r_ >= rr){
        for(int i = 0; i < n-1; i++) cout << r[i];
        cout << 1 << endl;
    }else{
        cout << r << endl;
    }
}