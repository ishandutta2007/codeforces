#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n,k,pw[N];

vector<int> ok[N],v,mx,bc,bg[N];

int main()
{
    scanf("%d",&T);
    int ans=0;
    for(int S=1;S<=(1<<10)-1;S++)
    {
        for(int i=0;i<10;i++)
            if(S>>i&1)
                ok[S].push_back(i);
        int mx=*ok[S].rbegin();
        bg[S].push_back(0);
        for(int i=1;i<=9;i++)
            bg[S].push_back(bg[S].back()*10+mx);
    }
    pw[0]=1;
    for(int i=1;i<=9;i++)
        pw[i]=pw[i-1]*10;
    while(T--)
    {
        scanf("%d%d",&n,&k);
        v.clear();
        while(n)
            v.push_back(n%10),n/=10;
        reverse(v.begin(),v.end());
        bc.clear();
        bc.push_back(0);
        for(int i=(int)v.size()-1;i>=0;i--)
            bc.push_back(bc.back()+v[i]*pw[v.size()-i-1]);
        reverse(bc.begin(),bc.end());
        int ans=2e9;
        for(int S=1;S<(1<<10);S++)
        {
            if(ok[S].size()>k)
                continue;
            long long s=0;
            bool big=0;
            bool can=1;
            for(int i=0;i<v.size();i++)
            {
                if(big)
                {
                    s=s*10+ok[S][0];
                    continue;
                }
                int eq=1;
                if(bg[S][v.size()-i-1]<bc[i+1])
                    eq=0;
                int val=(eq^1)+v[i];
                auto it=lower_bound(ok[S].begin(),ok[S].end(),val);
                if(it==ok[S].end())
                {
                    can=0;
                    break;
                }
                s=s*10+*it;
                big|=*it>v[i];
            }
            if(can)
                ans=min(1ll*ans,s);
        }
        printf("%d\n",ans);
    }
}