#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, m;
vector<int> G[500009];
vector<bool> fr[500009];
bool covered[500009];
vector<int> topics[500009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        fr[a].push_back(false);
        fr[b].push_back(false);
    }
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        topics[x].push_back(i);
        fr[i].push_back(false);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j: topics[i])
        {
            if(G[j].size()<i-1)
            {
                cout<<-1<<'\n';
                return 0;
            }
            for(int u=0; u<i-1; u++)
            {
                if(!fr[j][u])
                {
                    cout<<-1<<'\n';
                    return 0;
                }
            }
            if(fr[j][i-1])
            {
                cout<<-1<<'\n';
                return 0;
            }
            for(int sz: G[j])
            {
                if(fr[sz].size()>i-1)
                {
                    fr[sz][i-1]=true;
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j: topics[i])
        {
            cout<<j<<" ";
        }
    }
    cout<<'\n';

    return 0;
}