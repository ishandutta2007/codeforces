#include <bits/stdc++.h>
using namespace std;

int t;
int n[3];
const int maxn = 1e5 + 5;
typedef long long ll;
ll a[3][maxn];
ll ans;

ll sqr(ll v){
    return v * v;
}

void cal(ll val, int i, int j){
    int id1 = lower_bound(a[i] + 1, a[i] + 1 + n[i], val) - a[i];
    int id2 = upper_bound(a[j] + 1, a[j] + 1 + n[j], val) - a[j];
    id2--;
    ll val1 = a[i][id1];
    ll val2 = a[j][id2];
    //cout << val << " " << val1 << " " << val2 << " " << i << "  " << j << endl;
    if(id1 <= n[i] and id2 > 0){
        ans = min(ans, sqr(val1 - val2) + sqr(val1 - val) + sqr(val - val2));
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n[0] >> n[1] >> n[2];
        for(int i = 0;i < 3;i++){
            for(int j = 1;j <= n[i];j++){
                cin >> a[i][j];
            }
            sort(a[i] + 1, a[i] + 1 + n[i]);
        }
        ans = 4e18;
        for(int j = 1;j <= n[0];j++){
            cal(a[0][j], 1, 2);
            cal(a[0][j], 2, 1);
        }
        for(int j = 1;j <= n[1];j++){
            cal(a[1][j], 0, 2);
            cal(a[1][j], 2, 0);
        }
        for(int j = 1;j <= n[2];j++){
            cal(a[2][j], 0, 1);
            cal(a[2][j], 1, 0);
        }
        cout << ans << endl;
    }
    return 0;
}