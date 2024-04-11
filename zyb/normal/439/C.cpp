#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int dd=0,i,j,k,l,s=0,m,n,sum,os,qq=0;
    int a[100005],q[100005],w[100005];
    bool d[100005];
    memset(d,true,sizeof(d));
    scanf("%d%d%d",&n,&m,&k);
    int oo=m;
    sum=(m-k);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]%2==1)
        {
            s++;
            q[s]=i;
        }
        else
        {
            qq++;
            w[qq]=i;
        }
    }
    os=n-s;
    int z=s-sum;
    if (z%2==1)
    {
        printf("NO");
        return 0;
    }
    if (z/2+os<k)
    {
        printf("NO");
        return 0;
    }
    if (sum>s)
 {   printf("NO");
    return 0;
}
    printf("YES\n");
    for (i=1;i<sum;i++)
    {dd++;
    printf("1 %d\n",a[q[i]]);
    d[q[i]]=false;
    }
    m=m-sum;
    int ss=0;
    j=sum+1;
    l=1;
    for (i=1;i<=m&&dd<oo-1;i++)
    {
        if (j<=s)
        {
            dd++;
            printf("2 %d %d\n",a[q[j]],a[q[j+1]]);
            d[q[j]]=d[q[j+1]]=false;
            j+=2;
        }
        else
        {
            dd++;
            printf("1 %d\n",a[w[l]]);
            d[w[l]]=false;
            l++;
        }
    }
    /*if (dd==oo)
    return 0;*/
  /*  if (n==2&&oo==1)
    {
        printf("2 %d %d",a[1],a[2]);
        return 0;
    }*/
    /*int uu=(qq-l)+2;
    if (a[q[sum]]==0)
    uu--;
    printf("%d",uu);
    for (i=l;i<=qq;i++)
    {
    printf(" %d",a[w[i]]);
}
    if (a[q[sum]]!=0)
    printf(" %d",a[q[sum]]);*/
    int uu=0;
    for (i=1;i<=n;i++)
    {
        if (d[i])
        uu++;
    }
    if (uu==0)
    return 0;
    printf("%d ",uu);
    for (i=1;i<=n;i++)
    {
        if (d[i])
        printf("%d ",a[i]);
    }
}