#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll x0, y0, ax, ay, bx, by;
ll xs, ys, t;
vector<pair<ll, ll> > v;
ll di(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return abs(p1.F-p2.F)+abs(p1.S-p2.S);
}
pair<ll, ll> p0, strt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>p0.F>>p0.S>>ax>>ay>>bx>>by;
    cin>>strt.F>>strt.S>>t;
    while(1)
    {
        if(di(p0, strt)<=t)
        {
            v.push_back(p0);
        }
        else
        {
            if(p0.F>strt.F && p0.S>strt.S) break;
        }
        p0.F=ax*p0.F+bx;
        p0.S=ay*p0.S+by;
    }
    if(v.size()==0)
    {
        cout<<0<<endl;
        return 0;
    }
    int best=0;
    for(int i=0; i<v.size(); i++)
    {
        for(int j=i; j<v.size(); j++)
        {
            if(di(strt, v[i])+di(v[i], v[j])<=t) best=max(best, j-i+1);
            if(di(strt, v[j])+di(v[i], v[j])<=t) best=max(best, j-i+1);
        }
    }
    cout<<best<<endl;


    return 0;
}