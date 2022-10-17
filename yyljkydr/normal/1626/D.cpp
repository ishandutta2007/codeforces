#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T;

int n,s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        fill(s+1,s+n+1,0);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            s[x]++;
        }
        for(int i=1;i<=n;i++)
            s[i]+=s[i-1];
        int tt=1;
        while(tt<s[n])
            tt<<=1;
        int ans=tt-s[n]+2;
        for(int i=0;i<=n;i++)
        {
            int x=s[i];
            int t=1;
            while(t<x)
                t<<=1;
            int sum=t-x;
            for(int k=0;k<=18;k++)
            {
                t=(1<<k);
                if(s[i+1]-s[i]>t)
                    continue;
                int l=i+1,r=n+1;
                while(r-l>1)
                {
                    int mid=(l+r)>>1;
                    if(s[mid]-s[i]<=t)
                        l=mid;
                    else
                        r=mid;
                }
                int ss=sum+t-(s[l]-s[i]);
                x=s[n]-s[l];
                t=1;
                while(t<x)
                    t<<=1;
                ss+=t-x;
                ans=min(ans,ss);
            }
        }
        printf("%d\n",ans);
    }
}