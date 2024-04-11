#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int t[300009];
int h[300009];
vector<pii> ans;
void swapping(int c, int d)
{
    if(c==d) return;
    ans.push_back({c, d});
    swap(t[c], t[d]);
    h[t[c]]=c;
    h[t[d]]=d;
}
void doing(int x, int y)
{
    if(x==y) return;
    int c=h[x];
    int d=h[y];
    if(2*abs(c-d)>=n)
    {
        swapping(c, d);
        return;
    }
    if(c<=n/2 && d<=n/2)
    {
        swapping(c, n);
        swapping(d, n);
        swapping(c, n);
    }
    else if(c>n/2 && d>n/2)
    {
        swapping(c, 1);
        swapping(d, 1);
        swapping(c, 1);
    }
    else
    {
        if(c>n/2) swap(c, d);
        swapping(c, n);
        swapping(d, 1);
        swapping(1, n);
        swapping(c, n);
        swapping(d, 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        h[t[i]]=i;
    }
    for(int i=1; i<n; i++)
    {
        doing(i, t[i]);
    }
    cout<<ans.size()<<'\n';
    for(pii p: ans)
    {
        cout<<p.F<<" "<<p.S<<'\n';
    }
    return 0;
}