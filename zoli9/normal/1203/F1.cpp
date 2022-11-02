#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> pos;
vector<pii> neg;
int n, r;
bool rendez(pii x, pii y)
{
    return x.F+x.S>y.F+y.S;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>r;
    for(int i=0; i<n; i++)
    {
        pii cur;
        cin>>cur.F>>cur.S;
        if(cur.S>=0) pos.push_back(cur);
        else neg.push_back(cur);
    }
    sort(pos.begin(), pos.end());
    for(int i=0; i<pos.size(); i++)
    {
        if(pos[i].F>r)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        r+=pos[i].S;
    }
    sort(neg.begin(), neg.end(), rendez);
    for(int i=0; i<neg.size(); i++)
    {
        if(neg[i].F>r)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        r+=neg[i].S;
    }
    if(r>=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}