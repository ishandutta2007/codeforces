#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500;

int n, m;
void add(ll x, vector< pll > &a){
    ll cnt = 1;
    while(x % m == 0)
        x /= m, cnt *= m;
    if(a.size() > 0 && a[a.size() - 1].f == x)
        a[a.size() - 1].s += cnt;
    else
        a.pb({x, cnt});
}
void solve() {
    cin >> n >> m;
    vector<pll> a,b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        add(x, a);
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        add(x, b);
    }
    if(a == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}