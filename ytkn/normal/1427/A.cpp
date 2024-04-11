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
    int n; cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    int sum = 0;
    for(int i : b) sum += i;
    if(sum == 0){
        cout << "NO" << endl;
    }else if(sum < 0){
        sort(b.begin(), b.end());
        cout << "YES" << endl;
        for(int i : b) cout << i << ' ';
        cout << endl;
    }else{
        sort(b.begin(), b.end(), greater<int>());
        cout << "YES" << endl;
        for(int i : b) cout << i << ' ';
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}