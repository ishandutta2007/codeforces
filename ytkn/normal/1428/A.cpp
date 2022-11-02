#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

void solve(){
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
        cout << abs(y2-y1) << endl;
    }else if(y1 == y2){ 
        cout << abs(x2-x1) << endl;
    }else{
        cout << abs(y2-y1)+abs(x2-x1)+2 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}