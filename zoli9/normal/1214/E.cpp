#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
vector<pii> d;
vector<pii> ans;
int t[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int ddd;
        cin>>ddd;
        d.push_back({ddd, i});
    }
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    for(int i=0; i<n; i++)
    {
        if(i<n-1) ans.push_back({d[i].S*2-1, d[i+1].S*2-1});
        t[i]=d[i].S*2-1;
    }
    for(int i=0; i<n; i++)
    {
        if(i-d[i].F+1>=0)
        {
            ans.push_back({d[i-d[i].F+1].S*2-1, d[i].S*2});
            continue;
        }
        int j=i+d[i].F-1;
        ans.push_back({t[j], d[i].S*2});
        t[j+1]=d[i].S*2;
    }
    for(pii pp: ans)
    {
        cout<<pp.F<<" "<<pp.S<<endl;
    }


    return 0;
}