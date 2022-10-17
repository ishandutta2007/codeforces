#include<bits/stdc++.h>
using namespace std;

const int N=4e5+1e3+7;

int T,n;

struct P{
    int h,w,id;
}p[N];

bool cmp(P a,P b)
{
    return a.w<b.w;
}

int ans[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        fill(ans+1,ans+n+1,-1);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&p[i].h,&p[i].w),p[i].id=i,p[i+n]=p[i],swap(p[i+n].w,p[i+n].h);
        sort(p+1,p+n*2+1,cmp);
        int t=0;
        p[0].h=1e9;
        for(int i=1,j;i<=n*2;i=j+1)
        {
            j=i;
            while(p[j+1].w==p[i].w&&j+1<=n*2)
                j++;
            for(int k=i;k<=j;k++)
                if(p[k].h>p[t].h)
                    ans[p[k].id]=p[t].id;
            for(int k=i;k<=j;k++)
                if(p[k].h<p[t].h)
                    t=k;
        }
        for(int i=1;i<=n;i++)
            printf("%d%c",ans[i]," \n"[i==n]);
    }
}