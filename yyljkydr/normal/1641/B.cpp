#include<bits/stdc++.h>
using namespace std;

const int N=511;

int T,n;

vector<int>s;

vector<int>ans;

vector<pair<int,int> >ps;

map<int,int>vis;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        vis.clear();
        s.clear();
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            s.push_back(x);
            vis[x]^=1;
        }
        bool ok=1;
        for(auto [x,y]:vis)
            if(y)
                ok=0;
        if(!ok)
        {
            puts("-1");
            continue;
        }
        reverse(s.begin(),s.end());
        int pos=0;
        ps.clear();
        ans.clear();
        while(s.size())
        {
            int x=s.back();
            s.pop_back();
            pos++;
            vector<int>tmp;
            while(s.back()!=x)
            {
                tmp.push_back(s.back());
                s.pop_back();
                pos++;
            }
            s.pop_back();
            pos++;
            for(auto x:tmp)
                ps.push_back({pos,x}),pos++;
            ans.push_back(tmp.size()+1);
            for(auto x:tmp)
                s.push_back(x);
        }
        printf("%d\n",ps.size());
        for(auto [x,y]:ps)
            printf("%d %d\n",x,y);
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d%c",ans[i]*2," \n"[i+1==ans.size()]);
    }
}