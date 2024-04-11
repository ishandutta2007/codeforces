#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

ll n;
ll h[1000000];
ll h_next[1000000];

void simulate(){
    while(true){
        for(int i = 0; i < n; i++){
            h_next[i] = h[i];
        }
        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            if(h[i]+1 < h[i+1]){
                cnt++;
                h_next[i]++;
                h_next[i+1]--;
            }
        }
        for(int i = 0; i < n; i++){
            h[i] = h_next[i];
            cout << h[i] << ' ';
        }
        cout << endl;
        if(cnt == 0) break;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        sum += h[i];
    }
    ll x = (sum-(n*(n+1))/2 + n-1)/n;
    ll s = x*n + (n*(n+1))/2;
    ll m = x+n-(s-sum);
    for(int i = 1; i < n; i++){
        cout << x+i << ' ';
        if(x+i == m) cout << x+i << ' ';
    }
    if(m == x+n) cout << x+n << ' ';
    cout << endl;
}