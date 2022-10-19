#include<bits/stdc++.h>
using namespace std;
void norm(vector<pair<int,int>>& a)
{
    sort(a.begin(),a.end());
    vector<pair<int,int>> b;
    for(auto& [v,c] : a)
    {
        if(b.empty() || v!=b.back().first)b.emplace_back(v,0);
        b.back().second+=c;
    }
    a.swap(b);
}
void diff(vector<pair<int,int>>& a)
{
    vector<pair<int,int>> b;
    for(auto& [v,c] : a)
        if(c>1)b.emplace_back(0,c-1);
    for(size_t i=0;i+1<a.size();i++)
        b.emplace_back(a[i+1].first-a[i].first,1);
    a.swap(b);
    norm(a);
}
int solve()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        a.emplace_back(t,1);
    }
    norm(a);
    for(int i=1;i<n;i++)
        diff(a);
    assert(!a.empty());
    return 0*printf("%d\n",a[0].first);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}