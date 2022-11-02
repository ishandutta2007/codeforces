#include<bits/stdc++.h>
#define x(i)    T[i].x
#define y(i)    T[i].y
#define a(i)    T[i].a
#define maxn 1000050
using namespace std;
typedef long long LL;

struct node
{
    LL x,y,a;
    bool operator < (const node& N) const   {
        return x<N.x;
    }
}   T[maxn];

int n;
int pos[maxn],tmp[maxn];

bool cmp(int i,int j)
{
    return y(i)<y(j)||(y(i)==y(j)&&x(i)>x(j));
}

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lld%lld%lld",&x(i),&y(i),&a(i)),pos[i]=i;
    sort(T+1,T+n+1);
    sort(pos+1,pos+n+1,cmp);
    // for (int i=1;i<=n;++i)
    //     cout<<x(i)<<" "<<y(i)<<" "<<a(i)<<endl;
}

LL ans,dp[maxn];

int stk[maxn],tp;
LL x[maxn],y[maxn]={-(1LL<<60)};

bool pop(int i,int j,int k)
{
    return 1.0*(y[k]-y[j])/(x[k]-x[j])>1.0*(y[k]-y[i])/(x[k]-x[i]);
    // return (y[k]-y[j])*(x[k]-x[i])>(y[k]-y[i])*(x[k]-x[j]);
}

void calc(int l,int r)
{
    if (l==r) 
    {
        // cout<<pos[l]<<" "<<dp[pos[l]]<<" ("<<x(pos[l])<<","<<y(pos[l])<<","<<a(pos[l])<<") ";
        dp[pos[l]]+=x(pos[l])*y(pos[l])-a(pos[l]);
        // cout<<dp[pos[l]]<<endl;
        ans=max(ans,dp[pos[l]]);
        return ;
    }
    
    int mid=(l+r)>>1;
    for (int i=l;i<=r;++i)
        tmp[i]=pos[i];

    int pl=l,pr=mid+1;
    for (int i=l;i<=r;++i)
        if (tmp[i]<=mid)
            pos[pl++]=tmp[i];
        else
            pos[pr++]=tmp[i];

    calc(mid+1,r);

    // cout<<"["<<l<<","<<r<<"]"<<endl;
    tp=0;
    for (int k=l,j=l,p=mid+1;k<=mid;)
    {
        while (j<=mid&&y(pos[k])==y(pos[j]))    ++j;
        while (p<=r&&y(pos[p])<y(pos[k]))
        {
            x[pos[p]]=y(pos[p]),y[pos[p]]=dp[pos[p]];
            while (tp>1&&pop(stk[tp-1],stk[tp],pos[p])) --tp;
            stk[++tp]=pos[p++];
        }
        for (;k<j;++k)
        {
            int l=1,r=tp;
            while (l<r)
            {
                int mid=(l+r+1)>>1;
                if ((y[stk[mid]]-y[stk[mid-1]])>(x[stk[mid]]-x[stk[mid-1]])*x(pos[k]))
                    l=mid;
                else
                    r=mid-1;
            }
            // cout<<pos[k]<<" "<<stk[l]<<" : ";
            // for (int i=1;i<=tp;++i)
            //     cout<<stk[i]<<" ";
            // cout<<endl;
            dp[pos[k]]=max(dp[pos[k]],dp[stk[l]]-y(stk[l])*x(pos[k]));
        }
    }

    calc(l,mid);

    pl=l,pr=mid+1;
    
    for (int i=l;i<=r;++i)
        tmp[i]=pos[i];
    for (int i=l;i<=r;++i)
        if (pr>r||(pl<=mid&&cmp(tmp[pl],tmp[pr])))
            pos[i]=tmp[pl++];
        else
            pos[i]=tmp[pr++];
    // cout<<"sort:";
    // for (int i=l;i<=r;++i)
    //     cout<<pos[i]<<" ";
    // cout<<endl;
}

void solve()
{
    calc(1,n);
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}