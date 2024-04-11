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
unordered_map<int, bool> ma;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        int w;
        cin>>w;
        if(ma[w]) continue;
        ma[w]=true;
        if(q.size()==k)
        {
            ma[q.front()]=false;
            q.pop();
        }
        q.push(w);
    }
    cout<<q.size()<<endl;
    vi v;
    while(q.size()>0)
    {
        v.push_back(q.front());
        q.pop();
    }
    for(int i=(int)(v.size())-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}