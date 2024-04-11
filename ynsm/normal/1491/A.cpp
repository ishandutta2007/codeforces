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

int n, q, s, a[N];
int main()
{
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        s += a[i];
    }
    while(q--){
        int t, x;
        scanf("%d%d", &t, &x);
        if(t == 1){
            x--;
            s -= a[x];
            a[x] ^= 1;
            s += a[x];
        }else{
            printf("%d\n", (s >= x));
        }
    }
}