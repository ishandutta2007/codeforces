#include<bits/stdc++.h>
using namespace std;

const int N=1e7+1e3+7;

int n,a[N];

int vis[N],p[N],ptot,to[N];

void pre(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
            p[++ptot]=i,to[i]=i;
        for(int j=1;j<=ptot&&i*p[j]<=n;j++)
        {
            vis[i*p[j]]=1;
            to[i*p[j]]=p[j];
            if(i%p[j]==0)
                break;
        }
    }
}

int main()
{
    pre(1e7);
    scanf("%d",&n);
    vector<int>ans1,ans2;
    for(int i=1;i<=n;i++)
    {
        // int x=i+1;
        int x;
        scanf("%d",&x);
        vector<int>v;
        int t=x;
        while(x!=1)
        {
            int y=to[x];
            v.push_back(y);
            while(x%y==0)
                x/=y;
        }
        x=t;
        if(v.size()==1)
            ans1.push_back(-1),ans2.push_back(-1);
        else
        {
            int t=v[0],y=x;
            while(y%t==0)
                y/=t;
            ans1.push_back(t),ans2.push_back(y);
            // assert(__gcd(ans1.back()+ans2.back(),x)==1);
        }
    }
    for(auto x:ans1)
        printf("%d ",x);
    puts("");
    for(auto x:ans2)
        printf("%d ",x);
    puts("");
}