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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int a, b, k; cin >> a >> b >> k;
    if(b == 1){
        if(k == 0){
            cout << "Yes" << endl;
            cout << 1; for(int i = 0; i < a; i++) cout << 0;
            cout << endl;
            cout << 1; for(int i = 0; i < a; i++) cout << 0;
            cout << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }
    if(a == 0){
        if(k == 0){
            cout << "Yes" << endl;
            for(int i = 0; i < b; i++) cout << 1;
            cout << endl;
            for(int i = 0; i < b; i++) cout << 1;
            cout << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }
    if(a+b-2 < k){
        cout << "No" << endl;
        return 0;
    }

    if(k == 0){
        string ans;
        for(int i = 0; i < b; i++) ans += "1";
        for(int i = 0; i < a; i++) ans += "0";
        cout << "Yes" << endl;
        cout << ans << endl;
        cout << ans << endl;
        return 0;
    }

    cout << "Yes" << endl;
    string u;
    for(int i = 0; i < b-2; i++) u += '1';
    for(int i = 0; i < a-1; i++) u += '0';
    cout << "11";
    for(int i = 0; i < k-1; i++) cout << u[i];
    cout << "0";
    for(int i = k-1; i < u.size(); i++) cout << u[i];
    cout << endl;
    cout << "10";
    for(int i = 0; i < k-1; i++) cout << u[i];
    cout << "1";
    for(int i = k-1; i < u.size(); i++) cout << u[i];
    cout << endl;
}