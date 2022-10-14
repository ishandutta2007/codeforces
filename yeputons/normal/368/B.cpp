#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,dis=0, n,pp, m,  b, yo[100005] = {0}, dp[100005];
    int v[100005], ans[100005];
    cin >> n >> m;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    for(i=n-1; i>=0; i--) {
        if(yo[v[i]]==0) dis++, yo[v[i]]++;
        dp[i] = dis;
    }

    for(i=0; i<m; i++){
        scanf("%d", &pp);
        ans[i] = dp[pp-1];
    }
    for(i=0; i<m; i++) printf("%d\n", ans[i]);

    return 0;
}