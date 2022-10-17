#include<bits/stdc++.h>
using namespace std;

#define int long long

struct P{
    int x,y;
}p[4],t[4];

int T,ans;

int calc(int a)
{
    int x,y;
    int ret=1e18;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            x=p[i].x,y=p[j].y;
            if(i&1)
                x-=a;
            if(i&2)
                y-=a;
            int sum=0;
            for(int k=0;k<4;k++)
            {
                int ax=-p[k].x,ay=-p[k].y;
                if(k&1)
                    ax+=a;
                if(k&2)
                    ay+=a;
                sum+=abs(x+ax)+abs(y+ay);
                if(sum>ret)
                    break;
            }
            ret=min(ret,sum);
        }
    return ret;
}

map<vector<pair<int,int> >, int>vis;

signed main()
{
    scanf("%lld",&T);
    int r[4]={0,1,2,3};
    while(T--)
    {
        for(int i=0;i<4;i++)
            scanf("%lld%lld",&t[i].x,&t[i].y);
        int ans=1e18;
        do
        {
            for(int i=0;i<4;i++)
                p[i]=t[r[i]];
            for(int i=0;i<4;i++)
            for(int j=i+1;j<4;j++)
            {
                int k=abs(p[i].x-p[j].x);
                ans=min(ans,calc(k));
            }
            for(int i=0;i<4;i++)
            for(int j=i+1;j<4;j++)
            {
                int k=abs(p[i].y-p[j].y);
                ans=min(ans,calc(k));
            }
        }while(next_permutation(r,r+4));
        printf("%lld\n",ans);
    }
}