#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

struct Seg{
    int l,r;
};

bool operator <(const Seg &a,const Seg &b)
{
    return a.r<b.r;
}

bool cmp(Seg a,Seg b)
{
    return a.r-a.l>b.r-b.l;
}

set<Seg>s;

Seg a[N];

struct ND{
    int a,b,c;
};

vector<ND>ans;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].l,&a[i].r);
        sort(a+1,a+n+1,cmp);
        s.insert({1,n});
        ans.clear();
        for(int i=1;i<=n;i++)
        {
            auto it=s.lower_bound({0,a[i].r});
            if(it->l==a[i].l&&it->r==a[i].r)
                continue;
            else if(it->l==a[i].l)
            {
                ans.push_back({it->l,it->r,a[i].r+1});
                int L=it->l,R=it->r;
                s.erase(it);
                s.insert(a[i]);
                if(R>=a[i].r+2)
                    s.insert({a[i].r+2,R});
            }
            else 
            {
                ans.push_back({it->l,it->r,a[i].l-1});
                int L=it->l,R=it->r;
                s.erase(it);
                s.insert(a[i]);
                if(L<=a[i].l-2)
                    s.insert({L,a[i].l-2});
            }
        }
        for(auto [l,r]:s)
        {
            assert(l==r);
            ans.push_back({l,r,l});
        }
        s.clear();
        for(int i=0;i<ans.size();i++)
            printf("%d %d %d\n",ans[i].a,ans[i].b,ans[i].c);
        puts("");
    }
}