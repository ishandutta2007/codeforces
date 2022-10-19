#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,ll>> expand(const vector<int>& a,int m)
{
    vector<pair<int,ll>> res;
    for(size_t i=0;i<a.size();i++)
    {
        int v=a[i],c=1;
        while(v%m==0)v/=m,c*=m;
        if(res.empty() || res.back().first!=v)
            res.emplace_back(v,c);
        else res.back().second+=c;
    }
    return res;
}
int solve()
{
    int n,m,k;
    scanf("%d%d",&n,&m);
    vector<int> a(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    vector<int> b(k);
    for(int i=0;i<k;i++)
        scanf("%d",&b[i]);
    vector<pair<int,ll>> ta=expand(a,m);
    vector<pair<int,ll>> tb=expand(b,m);
    int res=(ta==tb);
    return 0*printf("%s\n",(res ? "Yes" : "No"));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}