#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
const int maxn = 2e5 + 5;

struct Bits{
    ll v[maxn * 2];
    void init(){
        memset(v, 0, sizeof(v));
    }
    void add(int p, ll val){
        for(int i = p;i < 2 * maxn;i += i & -i){
            v[i] += val;
        }
    }
    ll sum(int p){
        ll ret = 0;
        for(int i = p;i > 0;i -= i & -i){
            ret += v[i];
        } 
        return ret;
    }
    ll sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
}bit[2];

int n;
pi a[maxn];
int v[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].first;
    } 
    for(int i = 1;i <= n;i++){
        cin >> a[i].second;
        v[i] = a[i].second;
    }
    sort(v + 1, v + 1 + n);
    int tot = unique(v + 1, v + 1 + n) - v - 1;
    bit[0].init(), bit[1].init();
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        int y = lower_bound(v + 1, v + 1 + tot, a[i].second) - v;
        ll less = bit[0].sum(y);
        ll sum = bit[1].sum(y);
        ans += less * a[i].first - sum;
        bit[0].add(y, 1);
        bit[1].add(y, a[i].first);
    }
    cout << ans << endl;
    return 0;
}