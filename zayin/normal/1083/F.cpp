#include<bits/stdc++.h>
#define maxb 450
#define maxm (1<<14)
#define maxn 200050
using namespace std;

int n,m,q;

int a[maxn],b[maxn],c[maxn];

int L[maxn],R[maxn];

int N,val[maxn];

int ok;

int tag[maxb];
int cnt[maxb][maxm];

int B,block[maxn];

void init()
{
    scanf("%d%d%d",&n,&m,&q);
    for (int i=0;i<n;++i)  scanf("%d",&a[i]);
    for (int i=0;i<n;++i)  scanf("%d",&b[i]);

    for (int i=0;i<n;++i)  c[i]=a[i]^b[i];
    for (int i=n;i;--i) c[i]^=c[i-1];

    // for (int i=0;i<m;++i)
    // {
    //     for (int j=i;j<=n;j+=m)
    //         cout<<c[j]<<" ";
    //     cout<<endl;
    // }
    for (int i=0;i<m;++i)
    {
        val[L[i]=N++]=c[i];
        for (int j=i+m;j<=n;j+=m)
            val[L[j]=N++]=c[j]^val[L[j-m]];
        for (int j=i;j<=n;j+=m)
            R[j]=N-1;
        ok+=(bool)val[N-1];
    }

    B=sqrt(n);
    for (int i=0;i<=n;++i)  ++cnt[block[i]=i/B][val[i]];

    // for (int i=0;i<=n;++i)
    //     cout<<"group:"<<i<<" "<<val[i]<<" "<<L[i]<<" "<<R[i]<<" "<<block[i]<<endl;
}

int Ans()
{
    // cout<<"ok:"<<ok<<endl;
    // for (int i=0;i<=n;++i)
    //     cout<<c[i]<<" ";
    // cout<<endl;
    
    if (ok) return -1;
    int ans=0;
    // for (int i=0;i<=block[n];++i)
    //     cout<<"block:"<<i<<" "<<tag[i]<<" "<<cnt[i][tag[i]]<<endl;
    for (int i=0;i<=block[n];++i)
        ans+=cnt[i][tag[i]];
    return n+1-ans;
}

void change(int l,int r,int w)
{
    // cout<<"change:"<<l<<" "<<r<<" "<<w<<endl;
    if (val[r]^tag[block[r]])   --ok;
    for (;l<=r&&(!l||block[l]==block[l-1]);++l)
    {
        // cout<<"change:"<<l<<" "<<val[l]<<" "<<cnt[block[l]][val[l]]<<endl;
        --cnt[block[l]][val[l]];
        val[l]^=w;
        ++cnt[block[l]][val[l]];
    }
    // cout<<"change:"<<l<<" "<<r<<endl;
    for (;l<=r&&block[l]<block[r];l+=B)
        // cout<<"change block:"<<block[l]<<endl,
        tag[block[l]]^=w;
    for (;l<=r;++l)
    {
        // cout<<"change:"<<l<<" "<<val[l]<<" "<<cnt[block[l]][val[l]]<<" "<<tag[block[l]]<<endl;
        --cnt[block[l]][val[l]];
        val[l]^=w;
        ++cnt[block[l]][val[l]];
    }

    if (val[r]^tag[block[r]])   ++ok;
}

void solve()
{
    printf("%d\n",Ans());
    while (q--)
    {
        char op[5];
        int i,w,t,pre;
        scanf("%s%d%d",op,&i,&w);
        --i;
        if (*op=='a')
            pre=a[i],a[i]=w;
        else
            pre=b[i],b[i]=w;
        // cout<<"pre:"<<pre<<" "<<w<<endl;
        change(L[i],R[i],pre^w),c[i]^=pre^w;
        change(L[i+1],R[i+1],pre^w),c[i+1]^=pre^w;
        printf("%d\n",Ans());
    }
}

int main()
{
    init();
    solve();
    return 0;
}