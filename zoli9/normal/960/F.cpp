#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m;
int maxi=0;
set<pair<int, int> > t[100009]; // cost, hossz
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        t[i].insert({-1, 0});
    }
    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        auto it=t[a].lower_bound({c, -1});
        it--;
        int chossz=(it->S)+1;
        auto it2=t[b].lower_bound({c, -1});
        it2--;
        if(it2->S>=chossz) continue;
        it2++;
        while(it2!=t[b].end() && (it2->S)<=chossz)
        {
            t[b].erase(it2++);
        }
        t[b].insert({c, chossz});
        maxi=max(maxi, chossz);
    }
    cout<<maxi<<endl;
    return 0;
}