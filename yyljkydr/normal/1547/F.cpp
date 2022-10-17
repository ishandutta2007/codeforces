#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int T,n;

int a[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>g,ng;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),a[i+n]=a[i];
        g.clear();
        int ans=0;
        for(int i=n*2;i>=1;i--)
        {
            g.push_back(mp(a[i],i));
            for(auto &[x,y]:g)
                x=__gcd(x,a[i]);
            ng.clear();
            for(auto [x,y]:g)
                if(!ng.size()||x!=ng.back().fs)
                    ng.push_back(mp(x,y));
                else
                    ng.back().sd=y;
            g=ng;
            ans=max(ans,g[0].second-i);
        }
        printf("%d\n",ans);
    }
}