#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int w;
int h;
ll ans[1000009];
ll kum[1000009];
vector<ll> t;
multiset<pair<ll, int> > s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>w;
    for(int i=1; i<=n; i++)
    {
        cin>>h;
        t.resize(h+1);
        for(int j=1; j<=h; j++)
        {
            cin>>t[j];
        }
        if(w>=2*h)
        {
            ll maxi=0;
            for(int j=1; j<=h; j++)
            {
                maxi=max(maxi, t[j]);
                ans[j]+=maxi;
            }
            maxi=0;
            for(int j=h; j>=1; j--)
            {
                maxi=max(maxi, t[j]);
                ans[w-(h-j)]+=maxi;
            }
            kum[h+1]+=maxi;
            kum[w-h+1]-=maxi;
        }
        else
        {
            s.clear();
            for(int j=1; j<=w; j++)
            {
                if(j<=h) s.insert({-t[j], j});
                if(h-(w-j)-1>=1) s.erase({-t[h-(w-j)-1], h-(w-j)-1});
                ll plusz=-s.begin()->first;
                if(j+h<=w || h<j) plusz=max(0ll, plusz);
                ans[j]+=plusz;
            }
        }
    }
    for(int i=1; i<=w; i++)
    {
        kum[i]+=kum[i-1];
        cout<<ans[i]+kum[i]<<" ";
    }
    cout<<endl;

    return 0;
}