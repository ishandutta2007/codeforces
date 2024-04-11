#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll infi=1e16;
int n;
int ans[200009];
ll t[200009];
int m[2000009];
ll sumt[2000009];
ll getval(int cs, int k, int v, int x)
{
    if(v<x || x<k) return 0;
    if(k==v) return sumt[cs];
    return getval(2*cs, k, (k+v)/2, x)+getval(2*cs+1, (k+v)/2+1, v, x)+sumt[cs];
}
void adding(int cs, int k, int v, int x, int y, ll val)
{
    if(x<=k && v<=y)
    {
        sumt[cs]+=val;
        return;
    }
    if(v<x || y<k) return;
    adding(2*cs, k, (k+v)/2, x, y, val);
    adding(2*cs+1, (k+v)/2+1, v, x, y, val);
}
void suminit(int cs, int k, int v)
{
    if(k==v)
    {
        sumt[cs]=t[k];
        return;
    }
    suminit(2*cs, k, (k+v)/2);
    suminit(2*cs+1, (k+v)/2+1, v);
}



void ini(int cs, int k, int v)
{
    if(k==v)
    {
        m[cs]=k;
        return;
    }
    ini(2*cs, k, (k+v)/2);
    ini(2*cs+1, (k+v)/2+1, v);
    if(t[m[2*cs]]<t[m[2*cs+1]]) m[cs]=m[2*cs];
    else m[cs]=m[2*cs+1];
}
void elvesz(int cs, int k, int v, int x)
{
    if(v<x || x<k) return;
    if(k==v)
    {
        return;
    }
    elvesz(2*cs, k, (k+v)/2, x);
    elvesz(2*cs+1, (k+v)/2+1, v, x);
    if(getval(1, 0, n-1, m[2*cs])<getval(1, 0, n-1, m[2*cs+1])) m[cs]=m[2*cs];
    else m[cs]=m[2*cs+1];
}
int minhely()
{
    return m[1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>t[i];
    }
    ini(1, 0, n-1);
    suminit(1, 0, n-1);
    for(int i=1; i<=n; i++)
    {
        int idx=minhely();
        //cout<<i<<" "<<idx<<endl;
        ans[idx]=i;
        adding(1, 0, n-1, idx, idx, infi);
        if(idx<n-1) adding(1, 0, n-1, idx+1, n-1, -i);
        elvesz(1, 0, n-1, idx);
        //cout<<"round "<<i<<endl;
        //cout<<getval(1, 0, n-1, 0)<<" : "<<getval(1, 0, n-1, 1)<<" : "<<getval(1, 0, n-1, 2)<<endl;
    }
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}