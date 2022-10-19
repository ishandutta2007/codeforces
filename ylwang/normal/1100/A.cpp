#include <stdio.h>
int a[101];
int main()
{
    int n,k,i,j,mx=0,ans=0,t;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    //if(ans<0) ans=-ans;
    for(i=1;i<=k;i++)
    {
        int l=ans;
        for(j=i;j<=n;j+=k)
        {
            l-=a[j];
        }
        if(l<0) l=-l;
        if(l>mx) mx=l;
        //t=l;
    }
    printf("%d\n",mx);
    return 0;
}