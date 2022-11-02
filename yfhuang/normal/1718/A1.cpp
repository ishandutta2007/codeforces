#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;

ll a[maxn];
int n;

map<ll, int> cnt;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T; 
    while(T--){
        cin >> n;
        cnt.clear();
        ll pre = 0;
        cnt[pre]++;
        ll ans = n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            pre ^= a[i];
            if(cnt.count(pre) != 0){
                ans--;
                cnt.clear();
            }
            cnt[pre]++;
        }
        cout << ans << endl;
    }
    return 0;
}