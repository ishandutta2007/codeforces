#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn=5000+100;
const LL mod=1e9+7;

int a1[maxn];
vector<int> f[maxn],l[maxn],r[maxn];
int main()
{
    int n,m,K,x,y,u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a1[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        f[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i].size()==0) continue;
        sort(f[i].begin(),f[i].end());
        ///from left
        int cnt=0,now=0;
        for(int j=1;j<=n;j++)
        {
            if(a1[j]==i)
            {
                cnt++;
                if(cnt==f[i][now])
                {
                    l[i].push_back(j);
                    now++;
                    if(now==f[i].size()) break;
                }
            }
        }
        while(f[i].size()>l[i].size()) l[i].push_back(n+1);
        ///from right
        cnt=0,now=0;
        for(int j=n;j>=1;j--)
        {
            if(a1[j]==i)
            {
                cnt++;
                if(cnt==f[i][now])
                {
                    r[i].push_back(j);
                    now++;
                    if(now==f[i].size()) break;
                }
            }
        }
        while(f[i].size()>r[i].size()) r[i].push_back(-1);
    }
    f[0].push_back(0);
    l[0].push_back(0);
    r[0].push_back(0);///all from right 
    LL max_size=0,max_ways=1;
    for(int i1=0;i1<=n;i1++)
    {
        for(int j1=0;j1<f[i1].size();j1++)
        {
            int mid=l[i1][j1];/// [0,mid),(mid,n]
            if(mid==n+1) continue;
            LL sz=0,ways=1;
            for(int i=1;i<=n;i++)
            {
                if(f[i].size()==0) continue;
                LL a=0,b=0,c=0;
                for(int j=0;j<f[i].size();j++)
                {
                    if(l[i][j]<mid&&r[i][j]>mid) c++;
                    else if(l[i][j]<=mid) a++;
                    else if(r[i][j]>mid) b++;
                }
                if(i==i1&&i1!=0)
                {
                    a=0;
                    b+=c;
                    c=0;
                }
                if(a*b+a*c+b*c+c*(c-1)>0)
                {
                    sz+=2;
                    ways=(a*b+a*c+b*c+c*(c-1))%mod*ways%mod;
                }
                else if(a+b+c*2>0)
                {
                    sz+=1;
                    ways=(a+b+c*2)%mod*ways%mod;
                }
            }
            if(i1!=0) sz++;
            if(max_size<sz)
            {
                max_size=sz;
                max_ways=ways;
            }
            else if(max_size==sz)
            {
                max_ways=(max_ways+ways)%mod;
            }
        }
    }
    if(max_size==0) max_ways=1;
    max_ways%=mod;
    printf("%I64d %I64d\n",max_size,max_ways);
    return 0;
}