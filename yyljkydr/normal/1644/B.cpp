#include<bits/stdc++.h>
using namespace std;

int T,n;

map<vector<int>, int>vis;

vector<int>p;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        p.resize(n);
        for(int i=0;i<n;i++)
            p[i]=i;
        vis.clear();
        while(vis.size()<n)
        {
            random_shuffle(p.begin(),p.end());
            if(vis.count(p))
                continue;
            bool ok=1;
            for(int i=0;i+2<p.size();i++)
                if(p[i]+p[i+1]+2==p[i+2]+1)
                {
                    ok=0;
                    break;
                }
            if(ok)
                vis[p]=1;
        }
        for(auto [x,y]:vis)
        {
            for(auto w:x)
                printf("%d ",w+1);
            puts("");
        }
    }
}