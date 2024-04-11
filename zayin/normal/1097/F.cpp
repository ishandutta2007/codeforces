#include<bits/stdc++.h>
#define maxm 7005
#define maxn 100050
using namespace std;

int n,m;
bitset<maxm> S[maxn];
bitset<maxm> cur[maxm],ans[maxm];

int mu[maxm];
int pnum,p[maxm];
int noprime[maxm];

int main()
{
    scanf("%d%d",&n,&m);

    mu[1]=1;
    for (int i=2;i<maxm;++i)
    {
        if (!noprime[i])
            mu[p[pnum++]=i]=-1;
        for (int j=0;j<pnum&&i*p[j]<maxm;++j)
        {
            noprime[i*p[j]]=1;
            if (i%p[j])
                mu[i*p[j]]=-mu[i];
            else    break;
        }

        // cout<<i<<" "<<noprime[i]<<" "<<mu[i]<<endl;
    }

    for (int i=1;i<maxm;++i)
    {
        for (int j=i;j<maxm;j+=i)
            cur[j].set(i);
        for (int j=1;i*j<maxm;++j)
            if (mu[j])
                ans[i].set(i*j);
    }

    // for (int i=0;i<pnum;++i)
    //     cout<<p[i]<<endl;
    // for (int i=1;i<maxm;++i)
    //     cout<<i<<" "<<ans[i]<<endl;
    // cout<<endl<<endl;

    while (m--)
    {
        int op,x,y,z,v;
        scanf("%d",&op);
        if (op==1)
        {
            scanf("%d%d",&x,&v);
            S[x]=cur[v];
        } else
        if (op==2)
        {
            scanf("%d%d%d",&x,&y,&z);
            S[x]=S[y]^S[z];
        } else
        if (op==3)
        {
            scanf("%d%d%d",&x,&y,&z);
            S[x]=S[y]&S[z];
        } else
        if (op==4)
        {
            scanf("%d%d",&x,&v);
            printf("%d",(S[x]&ans[v]).count()&1);

            // cout<<" "<<S[x]<<" "<<ans[v]<<" "<<(S[x]&ans[v])<<endl;
        }
        
        // for (int i=1;i<=n;++i)
        //     cout<<i<<" "<<S[i]<<endl;
        // cout<<endl;
    }
    return 0;
}