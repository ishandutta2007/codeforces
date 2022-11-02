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
map<int, bool> ma;
int q[200009];
int sk=1;
int sv=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        int w;
        cin>>w;
        if(ma[w]) continue;
        ma[w]=true;
        if(sv-sk+1==k)
        {
            ma[q[sk]]=false;
            sk++;
        }
        sv++;
        q[sv]=w;
    }
    cout<<(sv-sk+1)<<endl;
    for(int i=sv; i>=sk; i--) cout<<q[i]<<" ";
    cout<<endl;
    return 0;
}