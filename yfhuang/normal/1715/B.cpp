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
ll n, k, b, s;
const int maxn = 1e5 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> k >> b >> s;
        if(s > k * b + n * (k - 1) or s < k * b){
            cout << -1 << endl;
            continue;
        }
        ll left = s - k * b;
        for(int i = 1;i <= n;i++){
            a[i] = 0;
        }
        a[n] = b * k;
        for(int i = 1;i <= n;i++){
            ll de = min(left, k - 1);
            a[i] += de;
            left -= de;
        }
        for(int i = 1;i <= n;i++){
            cout << a[i] << " \n"[i == n];
        }
    }
    return 0;
}