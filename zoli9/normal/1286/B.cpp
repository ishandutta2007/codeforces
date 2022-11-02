#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int n;
vi G[2009];
int c[2009];
int valasz[2009];
int root;
vi dfs(int x)
{
    if(G[x].size()==0)
    {
        if(c[x]!=0)
        {
            cout<<"NO"<<endl;
            exit(0);
        }
        return vi(1, x);
    }
    vi s;
    for(int sz: G[x])
    {
        vi sza=dfs(sz);
        for(int szsz: sza)
        {
            s.push_back(szsz);
        }
    }
    int mm=s.size();
    if(c[x]>mm)
    {
        cout<<"NO"<<endl;
        exit(0);
    }
    s.push_back(x);
    for(int i=mm-1; i>=c[x]; i--)
    {
        swap(s[i], s[i+1]);
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int pi;
        cin>>pi>>c[i];
        if(pi==0) root=i;
        else G[pi].push_back(i);
    }
    vi ans=dfs(root);
    for(int i=0; i<ans.size(); i++)
    {
        valasz[ans[i]]=i+1;
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<valasz[i]<<" ";
    }
    cout<<endl;
    return 0;
}