#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int sum(int a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}
int mul(int a,int b){
    return 1ll * a * b % mod;
}
int bp(int a, int b){
    int c = 1;
    while(b){
        if(b & 1)
            c = mul(c, a);
        a = mul(a, a);
        b >>= 1;
    }
    return c;
}
int inv(int a){
    return bp(a, mod - 2);
}



int n, m, w[N], p[N];
bool a[N];

int ask(){
    cout << "? ";
    for(int i = 0; i < m; i++)
            cout << a[i];
    cout << endl;
    cout.flush();
    int x;
    cin >> x;
    cout.flush();
    return x;
}
void answer(int x){
    cout << "! " << x << endl;
    cout.flush();
}
void solve() {
    cin >> n >> m;
    cout.flush();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++)
            a[j] = 0;
        a[i] = 1;
        w[i] = ask();
        a[i] = 0;
        p[i] = i;
    }
    sort(p, p + m, [](int i, int j){return w[i] < w[j];});
    int ans = 0;
    for(int j = 0; j < m; j++){
        int i = p[j];
        a[i] = 1;
        ll x = ask();
        if(ans + w[i] == x)
            ans += w[i];
        else
            a[i] = 0;
    }
    answer(ans);
}
int main()
{
    ios_base::sync_with_stdio(false);
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
    int t = 1;
//    cin >> t;
    while (t--)
        solve();
}