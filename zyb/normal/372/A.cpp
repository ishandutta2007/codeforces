#include<stdio.h>
#include<algorithm>
using namespace std;
int i,j,k,l,s,m,n,a[500005],b[500005],ans;
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int i=n,j=n>>1;
    for (;i>n>>1;i--)
    {
        while (j&&(a[i]<2*a[j]||b[j]))
        j--;
        if (j)
        ans--,b[j]=1;
    }
    printf("%d\n",n+ans);
}