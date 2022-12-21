#include<stdio.h>
#include<iostream>
using namespace std;
  int i,j,k,l,s,m,n,ll,oo=1000000;
    int a[1005];
    unsigned int aa[60005][1005],d[1005];
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (i%2==1)
        s+=a[i];
        else
        s-=a[i];
        if (s>ll)
        ll=s;
        if (s<oo)
        oo=s;
    }
    if (s>0)
    l=ll-s+500;
    else
    l=0-s+500;
    j=1;
    ll=l;
    oo=l;
    for (i=1;i<=n;i++)
    {
        for (k=1;k<=a[i];k++)
        {
            if (i%2==1)
            {
                aa[j][l]=1;
                j++;
                d[l]=j;
                ll=max(ll,l);
                l++;
            }
            else
            {
                
                l--;
                aa[j][l]=2;
                j++;
                d[l]=j;
                if (oo>l)
                oo=l;
            }
        }
    }
    for (k=ll;k>=oo;k--)
    {
    for (i=1;i<j;i++)
    if (aa[i][k]==0)
    printf(" ");
    else
    if (aa[i][k]==1)
    printf("/");
    else
    printf("\\");
    if (k)
    printf("\n");
}
}