#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,cnt[N],a[N];

int pos[N*2],sa[N],sb[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),cnt[a[i]]++;
    int ans=0;
    int x=max_element(cnt+1,cnt+100+1)-cnt;
    for(int y=1;y<=100;y++)
    {
        if(x==y)
            continue;
        for(int i=0;i<=n*2;i++)
            pos[i]=0;
        for(int i=1;i<=n;i++)
        {
            sa[i]=sa[i-1]+(a[i]==x);
            sb[i]=sb[i-1]+(a[i]==y);
            pos[sa[i]-sb[i]+n]=i;
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,pos[sa[i]-sb[i]+n]-i);
        }
    }
    printf("%d\n",ans);
}