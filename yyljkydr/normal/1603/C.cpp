#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=998244353;

int T,n,a[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>f,g;

int ans;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        f.clear();
        ans=0;
        for(int i=n;i>=1;i--)
        {
            g.clear();
            while(f.size())
            {
                auto [x,y]=f.back();
                f.pop_back();
                int k=(a[i]+x-1)/x;
                (ans+=1ll*y*(k-1)%P*i%P)%=P;
                if(g.size()&&a[i]/k==g.back().fs)
                    g.back().sd+=y;
                else
                    g.push_back({a[i]/k,y});
            }
            g.push_back({a[i],1});
            f=g;
        }
        printf("%d\n",ans);
    }
}