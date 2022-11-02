#include <bits/stdc++.h>
using namespace std;
int test;
vector<int> a;
vector<int> b;
int n;
vector<int> aindex[300009];
vector<int> bindex[300009];
vector<int> holvan;
int fa[3000009];
void init_fa(int cs, int k, int v)
{
    if(k==v)
    {
        fa[cs]=a[k];
        return;
    }
    init_fa(2*cs, k, (k+v)/2);
    init_fa(2*cs+1, (k+v)/2+1, v);
    fa[cs]=min(fa[2*cs], fa[2*cs+1]);
}
int minimum(int cs, int k, int v, int x, int y)
{
    if(v<x || y<k) return n+1;
    if(x<=k && v<=y) return fa[cs];
    return min(minimum(2*cs, k, (k+v)/2, x, y), minimum(2*cs+1, (k+v)/2+1, v, x, y));
}
void modosit(int cs, int k, int v, int x, int uj)
{
    if(v<x || x<k) return;
    if(k==v)
    {
        fa[cs]=uj;
        return;
    }
    modosit(2*cs, k, (k+v)/2, x, uj);
    modosit(2*cs+1, (k+v)/2+1, v, x, uj);
    fa[cs]=min(fa[2*cs], fa[2*cs+1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        a.resize(n);
        b.resize(n);
        holvan.resize(n);
        for(int i=1; i<=n; i++)
        {
            aindex[i].clear();
            bindex[i].clear();
        }
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            aindex[a[i]].push_back(i);
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
            bindex[b[i]].push_back(i);
        }
        bool lehetseges=true;
        for(int i=1; i<=n; i++)
        {
            if(aindex[i].size()!=bindex[i].size())
            {
                lehetseges=false;
                break;
            }
            for(int j=0; j<aindex[i].size(); j++)
            {
                holvan[bindex[i][j]]=aindex[i][j];
            }
        }
        if(!lehetseges)
        {
            cout<<"NO"<<endl;
            continue;
        }
        init_fa(1, 0, n-1);
        for(int i=0; i<n; i++)
        {
            if(minimum(1, 0, n-1, 0, holvan[i])!=a[holvan[i]])
            {
                lehetseges=false;
                break;
            }
            modosit(1, 0, n-1, holvan[i], n+1);
        }
        if(!lehetseges) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }


    return 0;
}