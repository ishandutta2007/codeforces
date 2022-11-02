#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int, int> pii;
typedef long long ll;
int n;
ll ans;
vector<pii> v;
int xCor=0;
int yCor=0;
vector<int> newx;
vector<int> newy;
vector<pii> tmp;
/*void kiir(vector<pii> tt)
{
    cout<<"tartalom:"<<endl;
    for(pii p: tt)
    {
        cout<<p.F<<" "<<p.S<<endl;
    }
    cout<<"vege"<<endl;
}*/
bool cy(pii a, pii b)
{
    if(a.S==b.S)
    {
        return a.F<b.F;
    }
    return a.S>b.S;
}
int m[2000009];
bool volt[200009];
void modosit(int cs, int k, int v, int x)
{
    if(x<k || v<x) return;
    m[cs]++;
    if(k==v) return;
    modosit(2*cs, k, (k+v)/2, x);
    modosit(2*cs+1, (k+v)/2+1, v, x);
}
int kerdez(int cs, int k, int v, int x, int y)
{
    if(v<x || y<k) return 0;
    if(x<=k && v<=y) return m[cs];
    int h1=kerdez(2*cs, k, (k+v)/2, x, y);
    int h2=kerdez(2*cs+1, (k+v)/2+1, v, x, y);
    return h1+h2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i].F>>v[i].S;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)
    {
        if(i==0 || v[i].F!=v[i-1].F) xCor++;
        newx.push_back(xCor);
    }
    for(int i=0; i<n; i++)
    {
        v[i].F=newx[i];
    }
    sort(v.begin(), v.end(), cy);
    newy.resize(n);
    for(int i=n-1; i>=0; i--)
    {
        if(i==n-1 || v[i].S!=v[i+1].S) yCor++;
        newy[i]=yCor;
    }
    for(int i=0; i<n; i++)
    {
        v[i].S=newy[i];
    }
    /*for(int i=0; i<n; i++)
    {
        cout<<v[i].F<<" : "<<v[i].S<<endl;
    }*/
    int cnt=0;
    while(cnt<n)
    {
        tmp.clear();
        int xx=v[cnt].F;
        if(!volt[xx])
        {
            volt[xx]=true;
            modosit(1, 0, n, xx);
        }
        tmp.push_back(v[cnt++]);
        while(cnt<n && v[cnt].S==tmp[0].S)
        {
            int xx=v[cnt].F;
            if(!volt[xx])
            {
                volt[xx]=true;
                modosit(1, 0, n, xx);
            }
            tmp.push_back(v[cnt++]);
        }
        //kiir(tmp);
        ll plusz=(ll)(kerdez(1, 0, n, 0, tmp[0].F))*(ll)(kerdez(1, 0, n, tmp[0].F, n));
        ans+=plusz;
        for(int i=1; i<tmp.size(); i++)
        {
            ll plusz=(ll)(kerdez(1, 0, n, tmp[i-1].F+1, tmp[i].F))*(ll)(kerdez(1, 0, n, tmp[i].F, n));
            ans+=plusz;
        }
        //cout<<"uj szint: "<<ans<<endl;
    }
    cout<<ans<<endl;

    return 0;
}