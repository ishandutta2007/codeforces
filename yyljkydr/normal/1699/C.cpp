#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=1e9+7;

int T,n,a[N];

int vis[N],pos[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]),pos[a[i]]=i,vis[i]=0;
        vis[n]=0;
        int L=pos[0],R=pos[0],len=0;
        vis[0]=1;
        int mex=1;
        long long ans=1;
        while(L!=0||R!=n-1)
        {
            int p=pos[mex];
            while(p<L)
            {
                L--;
                len++;
                vis[a[L]]=1;
            }
            while(p>R)
            {
                R++;
                len++;
                vis[a[R]]=1;
            }
            mex++;
            len--;
            while(vis[mex])
            {
                ans=ans*len%P;
                len--;
                mex++;
            }
        }
        printf("%lld\n",ans);
    }
}