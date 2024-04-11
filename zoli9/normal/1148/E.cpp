#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
vector<pii> a;
vector<int> b;
vector<pair<pii, int> > ans;
vector<pii> pos;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i].F;
        a[i].S=i+1;
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<n; i++)
    {
        if(a[i].F==b[i]) continue;
        if(a[i].F<b[i])
        {
            pos.push_back({b[i]-a[i].F, a[i].S});
        }
        else
        {
            int dist=a[i].F-b[i];
            while(pos.size()>0)
            {
                pii p=pos.back();
                if(p.F<=dist)
                {
                    ans.push_back({{p.S, a[i].S}, p.F});
                    dist-=p.F;
                    pos.pop_back();
                }
                else
                {
                    ans.push_back({{p.S, a[i].S}, dist});
                    pos[pos.size()-1].F-=dist;
                    dist=0;
                    break;
                }
            }
            if(dist>0)
            {
                cout<<"NO"<<'\n';
                return 0;
            }
        }
    }
    if(pos.size()>0)
    {
        cout<<"NO"<<'\n';
        return 0;
    }
    cout<<"YES"<<'\n';
    cout<<ans.size()<<'\n';
    for(pair<pii, int> p: ans)
    {
        cout<<p.F.F<<" "<<p.F.S<<" "<<p.S<<'\n';
    }
    return 0;
}