#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;
int k;
const int maxn = 105;
ll a[maxn];

ll f[maxn];
ll pref[maxn];

bool dfs(int n, int pre){
    if(n == -1){
        return true;
    }
    ll mx1 = 0, mx2 = 0, mxid1 = 0, mxid2 = 0;
    for(int i = 1;i <= k;i++){
        if(a[i] > mx1){
            mx2 = mx1;
            mxid2 = mxid1;
            mx1 = a[i];
            mxid1 = i;
        }else{
            if(a[i] > mx2){
                mx2 = a[i];
                mxid2 = i;
            }
        }
    }
    if(mx1 < f[n]){
        return false;
    }else{
        bool flag = false;
        if(mxid1 != pre){
            a[mxid1] -= f[n];
            flag |= dfs(n - 1, mxid1);
            a[mxid1] += f[n];
        }
        if(mx2 >= f[n] and mxid2 != pre){
            a[mxid2] -= f[n];
            flag |= dfs(n - 1, mxid2);
            a[mxid2] += f[n];
        }
        return flag;
    } 
} 

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    f[0] = 1, f[1] = 1;
    pref[0] = 1, pref[1] = 2;
    for(int i = 2;i <= 60;i++){
        f[i] = f[i-1] + f[i-2];
        pref[i] = pref[i-1] + f[i];
    }
    while(T--){
        cin >> k;
        ll sum = 0;
        int nz = 0;
        for(int i = 1;i <= k;i++){
            cin >> a[i];
            sum += a[i];
            nz += (a[i] > 0);
        }
        int n = -1;
        for(int i = 0;i <= 55;i++){
            if(pref[i] == sum){
                n = i;
                break;
            }
        }
        if(n == -1 or nz > n + 1){
            cout << "NO" << endl;
        }else{
            cout << (dfs(n, -1) ? "YES" : "NO") << endl; 
        }
    }
    return 0;
}