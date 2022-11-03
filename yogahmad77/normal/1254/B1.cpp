#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    long long jaw = 1e18;
    for(int i = 2; i <= sum; i++){
        if(sum % i > 0) continue;
        auto b = a;
        for(int j = 0; j < n; j++){
            b[j] %= i;
        }
        int tadi = -1;
        vector<int> c;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < b[j]; k++) c.pb(j);
        }
        long long ans = 0;
        for(int j = 0; j < sz(c); j += i){
            int l = j;
            int r = j + i - 1;
            int mid = (l + r) >> 1;
            // debug(l, r, mid);
            for(int k = l; k <= r; k++){
                ans += abs(c[k] - c[mid]);
            }
        }
        // debug(i, ans);
        jaw = min(jaw, ans);
    }
    if(jaw == 1e18) jaw = -1;
    cout << jaw << endl;
}