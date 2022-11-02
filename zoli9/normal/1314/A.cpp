#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
vector<pair<ll, ll> > v;
priority_queue<pair<ll, ll> > q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i].F;
    }
    for(int i=0; i<n; i++)
    {
        cin>>v[i].S;
    }
    sort(v.begin(), v.end());
    ll ans=0;
    int cnt=0;
    ll tm=0;
    while(cnt<n)
    {
        while(tm<v[cnt].F)
        {
            if(q.empty()) break;
            pair<ll, ll> p=q.top();
            q.pop();
            //cout<<p.F<<" es "<<tm<< " - "<<p.S<<endl;
            ans+=(p.F*(tm-p.S));
            tm++;
        }
        tm=v[cnt].F;
        int ti=v[cnt].F;
        while(cnt<n && v[cnt].F==ti)
        {
            q.push({v[cnt].S, v[cnt].F});
            cnt++;
        }
    }
    while(q.size()>0)
    {
        pair<ll, ll> p=q.top();
        q.pop();
        //cout<<p.F<<" es "<<tm<< " - "<<p.S<<endl;
        ans+=(p.F*(tm-p.S));
        tm++;
    }
    cout<<ans<<endl;

    return 0;
}