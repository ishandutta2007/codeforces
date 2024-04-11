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

int n, an, bn;
ll a[N], b[N];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        an = bn = 0;
        scanf("%d", &n);
        for(int i = 0; i < n + n; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            if(x)
                a[an++] = 1ll * x * x;
            else
                b[bn++] = 1ll * y * y;
        }
        sort(a, a + an);
        sort(b, b + bn);
        double ans = 0;
        for(int i = 0; i < n; i++)
            ans += sqrt(a[i] + b[i]);
        printf("%.12f\n", ans);
    }
}