#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int db[1009];
vi G[1009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        db[a]++;
        db[b]++;
    }
    vi leaves;
    for(int i=1; i<=n; i++)
    {
        if(db[i]==1) leaves.push_back(i);
    }
    for(int tt=1; tt<=n/2; tt++)
    {
        int x=leaves.back();
        leaves.pop_back();
        int y=leaves.back();
        leaves.pop_back();
        cout<<"? "<<x<<" "<<y<<endl;
        fflush(stdout);
        int lca;
        cin>>lca;
        if(lca==-1) return 0;
        if(lca==x || lca==y)
        {
            cout<<"! "<<lca<<endl;
            fflush(stdout);
            return 0;
        }
        for(int sz: G[x])
        {
            db[sz]--;
            if(db[sz]==1)
            {
                leaves.push_back(sz);
            }
        }
        for(int sz: G[y])
        {
            db[sz]--;
            if(db[sz]==1)
            {
                leaves.push_back(sz);
            }
        }
    }
    cout<<"! "<<(leaves.back())<<endl;
    fflush(stdout);
    return 0;
}