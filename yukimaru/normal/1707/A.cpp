#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> a(n),res(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int t=0;
    for(int i=n-1;i>=0;i--)
    {
        if(t>=a[i])res[i]=1;
        else if(t<q)res[i]=1,t++;
    }
    for(int i=0;i<n;i++)
        printf("%d",res[i]);
    return 0*printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}