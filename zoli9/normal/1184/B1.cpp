#include <bits/stdc++.h>
using namespace std;
int a[100009];
vector<pair<int, int> > v;
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    v.resize(m);
    for(int i=0; i<m; i++)
    {
        cin>>v[i].first;
        cin>>v[i].second;
    }
    sort(v.begin(), v.end());
    for(int i=1; i<m; i++)
    {
        v[i].second+=v[i-1].second;
    }
    for(int i=1; i<=n; i++)
    {
        int elso=0;
        int utolso=m-1;
        while(elso<=utolso)
        {
            int kozep=(elso+utolso)/2;
            if(a[i]>=v[kozep].first)
            {
                elso=kozep+1;
            }
            else
            {
                utolso=kozep-1;
            }
        }
        if(utolso<0) cout<<0<<" ";
        else cout<<v[utolso].second<<" ";
    }
    cout<<'\n';
    return 0;
}