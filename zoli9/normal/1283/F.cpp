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
int f[200009];
ll a[200009];
ll ujf[200009];
set<pair<ll, int> > s;
vpii answer;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    for(ll i=1; i<=n; i++)
    {
        ujf[i]=i;
        if(f[i]==0)
        {
            s.insert({i, i});
        }
    }
    for(int i=n-1; i>=1; i--)
    {
        auto it=s.begin();
        pair<ll, int> akt= *it;
        answer.push_back({a[i], it->second});
        f[a[i]]--;
        ujf[a[i]]=max(ujf[a[i]], (it->first));
        if(f[a[i]]==0)
        {
            s.insert({ujf[a[i]], (int)(a[i])});
        }
        s.erase(it);
    }
    cout<<a[1]<<endl;
    for(pii p: answer)
    {
        cout<<p.F<<" "<<p.S<<endl;
    }

    return 0;
}