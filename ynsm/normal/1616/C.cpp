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

int n, a[N], ans;
void solve()
{
    ans = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++){
        map<pii, int> cnt;
        for(int j = i + 1; j < n; j++){
            int l = j - i;
            int d = a[i] - a[j];
            int g = __gcd(l, abs(d));
            l /= g;
            d /= g;
            cnt[{l, d}]++;
        }
        for(auto x : cnt)
            ans = max(ans, x.s + 1);
    }
    printf("%d\n", n - ans);
}
int main()
{
    int t = 1;
    scanf ("%d", &t);
    while (t--)
        solve();
}