#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n;

int a[N];

int query(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    int res;
    scanf("%d",&res);
    return res;
}

int main()
{
    scanf("%d",&n);
    int res=100;
    int l=1,r=n;
    a[0]=a[n+1]=1e9;
    while(r-l+1>res)
    {
        int mid=(l+r)>>1;
        if(!a[mid])
            a[mid]=query(mid);
        if(!a[mid-1])
            a[mid-1]=query(mid-1);
        if(!a[mid+1])
            a[mid+1]=query(mid+1);
        res-=3;
        if(a[mid]<min(a[mid-1],a[mid+1]))
        {
            printf("! %d\n",mid);
            fflush(stdout);
            return 0;
        }
        else if(a[mid]>a[mid-1])
            r=mid-1;
        else 
            l=mid+1;
    }
    for(int i=l-1;i<=r+1;i++)
        if(!a[i]&&i!=0&&i<=n)
        {
            a[i]=query(i);
        }
    for(int i=l;i<=r;i++)
        if(a[i]<min(a[i-1],a[i+1]))
        {
            printf("! %d\n",i);
            fflush(stdout);
            return 0;
        }
}