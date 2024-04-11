#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int solve(vector<pii> v)
{
    sort(v.begin(),v.end());
    int L=-1,R = 1000000007;
    for (pii p:v)
    {
        L = max(L,p.first);
        R = min(R,p.second);
    }
    return R-L;
}

int main ()
{
    vector<pii> v;
    int n;
    scanf("%d",&n);
    vector<pii> vvv;
    for (int i=1;i<=n;++i)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        v.push_back(make_pair(l,r));
        vvv.push_back(make_pair(r,l));
    }
    int ans=0;
    sort(v.begin(),v.end());
    vector<pii> vv;
    for (int i=0;i<n-1;++i)
    {
        vv.push_back(v[i]);
    }
    ans = max(ans,solve(vv));
    reverse(v.begin(),v.end());
    vv.clear();
    for (int i=0;i<n-1;++i)
    {
        vv.push_back(v[i]);
    }
    ans = max(ans,solve(vv));
    sort(vvv.begin(),vvv.end());
    vv.clear();
    for (int i=0;i<n-1;++i)
    {
        vv.push_back(make_pair(vvv[i].second,vvv[i].first));
    }
    ans = max(ans,solve(vv));
    reverse(vvv.begin(),vvv.end());
    vv.clear();
    for (int i=0;i<n-1;++i)
    {
        vv.push_back(make_pair(vvv[i].second,vvv[i].first));
    }
    ans = max(ans,solve(vv));
    printf("%d\n",ans);
}