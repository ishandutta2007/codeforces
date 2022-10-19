#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N];

set<int>s,pos;

vector<int>ans;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        pos.clear();
        s.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]),pos.insert(i);
        for(int i=0;i<n;i++)
            if(__gcd(a[i],a[(i+1)%n])==1)
                s.insert(i);
        int x=0;
        ans.clear();
        while(s.size())
        {
            auto y=s.lower_bound(x);
            if(y==s.end())
                y=s.begin();
            int p=*y;
            y=pos.upper_bound(p);
            if(y==pos.end())
                y=pos.begin();
            int ap=*y;
            ans.push_back(ap);
            pos.erase(ap);
            s.erase(p);
            s.erase(ap);
            x=(ap+1)%n;
            if(!pos.size())
                break;
            y=pos.upper_bound(p);
            if(y==pos.end())
                y=pos.begin();
            ap=*y;
            if(__gcd(a[p],a[ap])==1)
                s.insert(p);
        }
        printf("%d ",ans.size());
        for(auto x:ans)
            printf("%d ",x+1);
        puts("");
    }
}