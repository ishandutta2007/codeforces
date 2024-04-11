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
int paar[1000009];
set<int> s;
vector<int> G[1000009];
int elszam=0;
void dfs(int x)
{
    paar[x]=1;
    for(int sz: G[x]) if(paar[sz]==0) dfs(sz);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        paar[bb]=aa;
    }
    for(int i=1; i<=2*n; i++)
    {
        if(paar[i]==0)
        {
            s.insert(i);
        }
        else
        {
            auto it=s.find(paar[i]);
            it++;
            while(it!=s.end())
            {
                G[*it].push_back(paar[i]);
                G[paar[i]].push_back(*it);
                elszam++;
                if(elszam>=n)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                it++;
            }
            s.erase(paar[i]);
        }
    }
    if(elszam!=n-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    dfs(1);
    for(int i=1; i<=2*n; i++)
    {
        if(paar[i]==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}