#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
vector<pii> as;
vector<pii> de;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x, y;
        cin>>x>>y;
        if(x>y) de.push_back({y, i});
        else as.push_back({-x, i});
    }
    sort(as.begin(), as.end());
    sort(de.begin(), de.end());
    if(as.size()>de.size())
    {
        cout<<as.size()<<'\n';
        for(pii p: as) cout<<p.S<<" ";
        cout<<endl;
    }
    else
    {
        cout<<de.size()<<'\n';
        for(pii p: de) cout<<p.S<<" ";
        cout<<endl;
    }
    return 0;
}