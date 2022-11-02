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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int ps=n/2;
    int pt=n/2;
    if(n%2) pt++;
    int last=-1;
    int db=0;
    vpii v, v2;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int aa;
        cin>>aa;
        if(aa>0)
        {
            if(aa%2==last)
            {
                v.push_back({db, last});
            }
            else if(last==-1)
            {
                v2.push_back({db, aa%2});
            }
            else
            {
                ans++;
            }
            if(aa%2)
            {
                pt--;
                last=1;
            }
            else
            {
                ps--;
                last=0;
            }
            db=0;
        }
        else
        {
            db++;
        }
    }
    if(last==-1)
    {
        if(n==1) cout<<0<<endl;
        else cout<<1<<endl;
        return 0;
    }
    if(db>0)
    {
        v2.push_back({db, last});
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for(pii p: v)
    {
        if(p.S==0)
        {
            if(ps>=p.F)
            {
                ps-=p.F;
            }
            else
            {
                ans+=2;
            }
        }
        else
        {
            if(pt>=p.F)
            {
                pt-=p.F;
            }
            else
            {
                ans+=2;
            }
        }
    }
    for(pii p: v2)
    {
        if(p.S==0)
        {
            if(ps>=p.F)
            {
                ps-=p.F;
            }
            else
            {
                ans+=1;
            }
        }
        else
        {
            if(pt>=p.F)
            {
                pt-=p.F;
            }
            else
            {
                ans+=1;
            }
        }
    }
    cout<<ans<<endl;




    return 0;
}