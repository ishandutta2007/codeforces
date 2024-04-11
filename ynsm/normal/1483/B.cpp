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

int n, a[N], nxt[N], prv[N], k, ans[N];
set<int> st;
void solve()
{
    st.clear();
    k = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        nxt[i] = (i + 1) % n;
        prv[i] = (i + n - 1) % n;
        if (__gcd(a[i], a[nxt[i]]) == 1)
            st.insert(i);
    }
    int p = 0;
    while (!st.empty())
    {
        if (st.lower_bound(p) == st.end())
        {
            p = 0;
            continue;
        }

        int i = *st.lower_bound(p);
        int j = nxt[i];
        int q = nxt[j];
        nxt[i] = q;
        prv[q] = i;

        st.erase(i);
        st.erase(j);
        ans[k++] = j;
        if (i == j)
            break;
        if (__gcd(a[i], a[q]) == 1)
            st.insert(i);
        p = q;
    }
    printf("%d ", k);
    for (int i = 0; i < k; i++)
        printf("%d ", ans[i] + 1);
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}