#include<stdio.h>
#include<algorithm>
using namespace std;
int n,i,j,m,b[200005],a[200005],ans,s;
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    scanf("%d",&b[i]);
    sort(b+1,b+1+n);
    for (i=1;i<=n;i++)
    if (b[i]!=b[i-1])
    a[++m]=b[i];
    n=m;
    for (i=1;i<=n;i++)
    {
        for (j=2;j*a[i]<=a[n]+a[i];j++)
        {
            int l=i,r=n;
            s=0;
            while (l<=r)
            {
                int mid=(l+r)>>1;
                if (a[mid]<j*a[i])
                {
                    l=mid+1;
                    s=a[mid];
                }
                else
                r=mid-1;
            }
            ans=max(ans,s%a[i]);
        }
    }
    printf("%d\n",ans);
}