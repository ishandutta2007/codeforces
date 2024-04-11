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

int n, a[N];

void solve() {
    cin >> n;
    ll x = 0;
    bool flag = 0,ans = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        x += a[i];
        if(x < 0)
            ans = 0;
        if(x == 0)
            flag = 1;
        if(flag && x != 0)
            ans = 0;
    }
    if(x)
        ans = 0;
    if(ans)
        puts("YES");
    else
        puts("NO");
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