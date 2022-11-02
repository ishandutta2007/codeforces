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
int n, m;

const int maxn = 1e5 + 5;
vector<ll> c[maxn];
__int128 pre[maxn];

bool cmp(int i, int j){
    return pre[i] < pre[j];
}

int id[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            __int128 p = 0;
            pre[i] = 0;
            for(int j = 1;j <= m;j++){
                ll val;
                cin >> val;
                c[i].push_back(val);
                p += val; 
                pre[i] += p;
            }
        }
        for(int i = 1;i <= n;i++){
            id[i] = i;
        }
        sort(id + 1, id + 1 + n, cmp);
        ll ans = pre[id[2]] - pre[id[1]];
        cout << id[1] << " " << ans << endl;
    }
    return 0;
}