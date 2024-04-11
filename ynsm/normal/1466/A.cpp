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
        int ans = 0;
        for(int i = 1; i <= 50; i++){
            bool found = false;
            for(int j = 0; j < n; j++)
                for(int q = 0; q < j; q++)
                    if(a[j] - a[q] == i)
                        found = true;
            if(found)
                ans++;
        }
        printf("%d\n", ans);
    }
}