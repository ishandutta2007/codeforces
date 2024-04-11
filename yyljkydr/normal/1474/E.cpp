#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int p[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            p[i]=i;
        int j=1;
        int x=n-1;
        long long ans=0;
        vector<pii>v;
        while(x)
        {
            int t=j==1?1:2;
            int s=min(t,x);
            x-=s;
            ans+=1ll*s*(n-j)*(n-j);
            swap(p[1],p[n-j+1]);
            v.push_back(mp(n-j+1,1));
            if(s==2)
            {
                swap(p[n],p[j]);
                v.push_back(mp(j,n));
            }
            j++;
        }
        reverse(v.begin(),v.end());
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++)
            printf("%d%c",p[i]," \n"[i==n]);
        printf("%d\n",n-1);
        for(auto [x,y]:v)
            printf("%d %d\n",x,y);
    }
}