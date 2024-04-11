#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()


const int maxn = 2e5 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        ll n, k;
        cin >> n >> k;
        ll mx = -1e9 - 7;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        for(int i = 1;i <= n;i++){
            a[i] = mx - a[i];
        }
        mx = -1e18;
        for(int i = 1;i <= n;i++){
            mx = max(a[i], mx);
        }
        k--;
        if(k & 1){
            for(int i = 1;i <= n;i++){
                a[i] = mx - a[i];
            }
        }
        for(int i = 1;i <= n;i++){
            cout << a[i];
            if(i == n){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }
    return 0;
}