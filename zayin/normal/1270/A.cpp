#include<bits/stdc++.h>
using namespace std;
int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,k1,k2;
        scanf("%d%d%d",&n,&k1,&k2);
        int mx1=0,mx2=0,t;
        while (k1--)    {
            scanf("%d",&t);
            mx1=max(mx1,t);
        }
        while (k2--)    {
            scanf("%d",&t);
            mx2=max(mx2,t);
        }
        puts(mx1>mx2?"YES":"NO");
    }
    return 0;
}