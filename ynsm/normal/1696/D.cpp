#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 500500, inf = 1e9;

int n, a[N];
int l[N][2], r[N][2];
int dp[N];
vector< int > g[N][2];

int t[N << 3];
void build(int v, int tl, int tr){
    t[v] = inf;
    if(tl == tr)
        return;
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
}
int get(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l || l > r)
        return inf;
    if(l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return min(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
}
void upd(int v, int tl, int tr, int p, int x){
    if(tl == tr){
        t[v] = x;
        return;
    }
    int tm = (tl +tr) >> 1;
    if(p <= tm)
        upd(v << 1, tl, tm, p, x);
    else
        upd(v << 1 | 1, tm + 1, tr, p, x);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++)
            g[i][j].clear();
        {
            stack< int > st;
            for(int i = 0; i < n; i++){
                while(!st.empty() && (a[st.top()] > a[i]) == j)
                    st.pop();
                if(st.empty())
                    l[i][j] = 0;
                else
                    l[i][j] = st.top() + 1;
                st.push(i);
            }
        }
        {
            stack< int > st;
            for(int i = n - 1; i >= 0; i--){
                while(!st.empty() && (a[st.top()] > a[i]) == j)
                    st.pop();
                if(st.empty())
                    r[i][j] = n - 1;
                else
                    r[i][j] = st.top() - 1;
                st.push(i);
            }
        }
    }
    for(int j = 0; j < 2; j++) {
        build(2 | j, 0, n - 1);
        for (int i = 0; i < n; i++)
            g[r[i][j]][j ^ 1].pb(i);
//        for (int i = 0; i < n; i++)
//            cerr << j << " " << l[i][j] << " " << r[i][j] << endl;
    }
    for(int i = 0; i < n; i++){
        dp[i] = inf;
        for(int j = 0; j < 2; j++)
            dp[i] = min(dp[i], get(2 | j, 0, n - 1, l[i][j], i - 1) + 1);
        if(i == 0)
            dp[i] = 0;

        for(int j = 0; j < 2; j++) {
            upd(2 | j, 0, n - 1, i, dp[i]);
            for(auto q : g[i][j])
                upd(2 | j, 0, n - 1, q, inf);
        }
    }

    cout << dp[n - 1] << endl;
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