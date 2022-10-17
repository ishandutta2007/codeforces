#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int T;

int n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n*2;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n*2+1);
        int ok=0;
        for(int i=1;i<n*2;i++)
        {
            int x=a[i]+a[n*2];
            multiset<int>s;
            for(int j=1;j<=n*2;j++)
                s.insert(a[j]);
            vector<pair<int,int> >ans;
            while(s.size())
            {
                int u=*(--s.end());
                s.erase(--s.end());
                int v=x-u;
                auto p=s.lower_bound(v);
                if(p==s.end()||*p!=v)
                    break;
                ans.push_back(make_pair(u,v));
                s.erase(p);
                x=u;
            }
            if(ans.size()==n)
            {
                puts("YES");
                printf("%d\n",a[i]+a[n*2]);
                for(auto [x,y]:ans)
                    printf("%d %d\n",x,y);
                ok=1;
                break;
            }
        }
        if(!ok)
            puts("NO");
    }
}