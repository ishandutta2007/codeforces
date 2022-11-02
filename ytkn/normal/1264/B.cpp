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
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a+b+c+d == 1){
        cout << "YES" << endl;
        if(a == 1) cout << 0 << endl;
        if(b == 1) cout << 1 << endl;
        if(c == 1) cout << 2 << endl;
        if(d == 1) cout << 3 << endl;
        return 0;
    }

    if(a == b+1 && c == 0 && d == 0){
        cout << "YES" << endl;
        for(int i = 0; i < b; i++) cout << "0 1 ";
        cout << "0" << endl;
        return 0;
    }

    if(d == c+1 && a == 0 && b == 0){
        cout << "YES" << endl;
        for(int i = 0; i < c; i++) cout << "3 2 ";
        cout << "3" << endl;
        return 0;
    }

    if(a > b || d > c){
        cout << "NO" << endl;
        return 0;
    }

    if(abs((b-a)-(c-d)) >= 2){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    if(a == b){
        for(int i = 0; i < a; i++) cout << "0 1 ";
        for(int i = 0; i < d; i++) cout << "2 3 ";
        if(c > d) cout << "2 ";
        cout << endl;
        return 0;
    }

    if(c == d){
        for(int i = 0; i < d; i++) cout << "3 2 ";
        for(int i = 0; i < a; i++) cout << "1 0 ";
        if(b > a) cout << "1 ";
        cout << endl;
        return 0;
    }

    if(b-a == c-d){
        int x = c-d;
        for(int i = 0; i < x-1; i++) cout << "1 2 ";
        cout << "1 ";
        for(int i = 0; i < a; i++) cout << "0 1 ";
        cout << "2 ";
        for(int i = 0; i < d; i++) cout << "3 2 ";
        cout << endl;
    }else if(b-a > c-d){
        int x = c-d;
        for(int i = 0; i < x-1; i++) cout << "1 2 ";
        cout << "1 2 ";
        for(int i = 0; i < d; i++) cout << "3 2 ";
        cout << "1 ";
        for(int i = 0; i < a; i++) cout << "0 1 ";
        cout << endl;
    }else{
        int x = b-a;
        cout << "2 ";
        for(int i = 0; i < x-1; i++) cout << "1 2 ";
        cout << "1 ";
        for(int i = 0; i < a; i++) cout << "0 1 ";
        cout << "2 ";
        for(int i = 0; i < d; i++) cout << "3 2 ";
        cout << endl;
    }
}