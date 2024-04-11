#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int ans = 0;
        for(int i = 0, j = -1; i < n; i++){
            if(j < a[i])
                j = a[i], ans++;
            else if(j == a[i])
                j = a[i] + 1, ans++;
        }
        printf("%d\n", ans);
    }
}