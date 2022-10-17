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


void solve () {
    int n, y;
    y = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        y += x;
    }
    if (y % n == 0)
        printf ("0\n");
    else
        printf ("1\n");
}
int main () {
    int t = 1;
    scanf ("%d", &t);
    while (t--)
        solve ();
}