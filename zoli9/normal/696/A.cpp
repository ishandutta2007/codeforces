#include <bits/stdc++.h>
using namespace std;
map<long long, long long> m;
int q;
long long loga(long long x)
{
    if(x==1) return 0;
    return 1+loga(x/2);
}
int main()
{
    cin>>q;
    for(int qq=1; qq<=q; qq++)
    {
        int tip;
        cin>>tip;
        if(tip==1)
        {
            long long u, v, cost;
            cin>>u>>v>>cost;
            while(u!=v)
            {
                if(u>v)
                {
                    m[u]+=cost;
                    u/=2;
                }
                else
                {
                    m[v]+=cost;
                    v/=2;
                }
            }
        }
        else
        {
            long long u, v;
            cin>>u>>v;
            long long ans=0;
            while(u!=v)
            {
                if(u>v)
                {
                    ans+=m[u];
                    u/=2;
                }
                else
                {
                    ans+=m[v];
                    v/=2;
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}