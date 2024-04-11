#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,z,res=0;
    scanf("%d%d",&n,&z);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        res=max(res,a|z);
    }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}