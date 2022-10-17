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

int n, v, u, a[N];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &u, &v);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        bool bad = 1;
        for(int i = 1; i < n; i++)
            bad &= (abs(a[i] - a[i - 1]) <= 1);
        if(!bad){
            printf("0\n");
        }else{
            int ans = 2e9;
            ans = min(ans, v + v);
            ans = min(ans, v + u);
            bool bad = 1;
            for(int i = 1; i < n; i++)
                bad &= (abs(a[i] - a[i - 1]) <= 0);    
            if(!bad){
                ans = min(ans, u);
                ans = min(ans, v);
            }
            printf("%d\n", ans);
        }
    }
}