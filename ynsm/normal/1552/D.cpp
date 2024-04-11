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
int f(int i, int s){
    if(i == n)
        return s == 0;
    return f(i + 1, s) + f(i + 1, s + a[i]) + f(i + 1, s - a[i]);
}
void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    puts(f(0, 0) > 1 ? "YES" : "NO");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}