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

int n, a[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    ll s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    multiset<ll> st;
    st.insert(s);
    for (int i = n - 1; i >= 0; i--)
    {
        while (*st.rbegin() > a[i])
        {
            ll x = *st.rbegin();
            st.erase(st.find(x));
            st.insert(x / 2);
            st.insert(x - x / 2);
        }

        if (*st.rbegin() == a[i])
        {
            ll x = *st.rbegin();
            st.erase(st.find(x));
        }
        else
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}