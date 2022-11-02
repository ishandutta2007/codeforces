#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vi G[100009];

vector<pii> input;
int ans[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        input.push_back({a, b});
    }
    int szam=0;
    for(int i=0; i<n-1; i++)
    {
        if(G[input[i].F].size()==1 || G[input[i].S].size()==1)
        {
            ans[i]=(szam++);
        }
    }
    for(int i=0; i<n-1; i++)
    {
        if(!(G[input[i].F].size()==1 || G[input[i].S].size()==1))
        {
            ans[i]=(szam++);
        }
    }
    for(int i=0; i<n-1; i++)
    {
        cout<<ans[i]<<'\n';
    }


    return 0;
}