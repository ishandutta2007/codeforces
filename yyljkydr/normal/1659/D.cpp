#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,c[N],a[N],p[N];

// c_i = a_i * (i - 1) + (p_i) - i

// p_i is the position of i-th zero

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        for(int i=1;i<=n;i++)
            a[i]=p[i]=0;
        int x=1;
        while(x<=n&&c[x]==0)
            x++;
        a[x]=1;
        for(int i=x,j=x+1;i<=n;i++)
        {
            p[i]=c[i]+i-a[i]*(i-1);
            while(j<p[i])
                a[j]=1,j++;
            a[j]=0;
            j++;
            if(j>n)
                break;
        }
        for(int i=1;i<=n;i++)
            printf("%d%c",a[i]," \n"[i==n]);
    }
}