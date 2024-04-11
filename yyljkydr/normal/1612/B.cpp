#include<bits/stdc++.h>
using namespace std;

const int N=111;

int T,n,a,b;

int p[N];

set<int>s;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&a,&b);
        p[1]=a,p[n]=b;
        s.clear();
        for(int i=1;i<=n;i++)
            if(i!=a&&i!=b)
                s.insert(i);
        for(int i=2;i<=n/2;i++)
            p[i]=*s.rbegin(),s.erase(*s.rbegin());
        for(int i=n-1;i>=n/2+1;i--)
            p[i]=*s.begin(),s.erase(*s.begin());
        if(*min_element(p+1,p+n/2+1)!=a||*max_element(p+n/2+1,p+n+1)!=b)
            puts("-1");
        else
        {
            for(int i=1;i<=n;i++)
                printf("%d%c",p[i]," \n"[i==n]);
        }
    }
}