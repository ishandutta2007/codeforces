#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll a1, a2;
    if(a < c){
        a1 = 1;
    }else{
        a1 = -1;
    }
    if(a*b > c){
        a2 = b;
    }else{
        a2 = -1;
    }
    cout << a1 << ' ' << a2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}