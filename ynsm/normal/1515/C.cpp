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

void solve()
{
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    set<pii> st;
    for (int i = 1; i <= m; i++)
        st.insert({0, i});
    printf("YES\n");
    for (int i = 0; i < n; i++)
    {
        int y;
        scanf("%d", &y);
        auto it = st.begin();
        int a = y + it->f;
        int b = it->s;
        st.erase(it);
        st.insert({a, b});
        printf("%d ", b);
    }
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}