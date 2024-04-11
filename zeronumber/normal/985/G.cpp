#include<bits/stdc++.h>
#define maxn 201000

using namespace std;
typedef unsigned long long ull;
ull ans,a,b,c,d;
int n,m,r,sz[maxn],x[maxn],y[maxn],s,t,u,v,e[3];
vector <int> h[maxn],g[maxn];

ull calc(int o,int p,int q){
    e[0]=o; e[1]=p; e[2]=q; sort(e,e+3);
    return a*e[0]+b*e[1]+c*e[2];
}

int main()
{
    cin >> n >> m;
    cin >> a >> b >> c;
    for (int i=0;i<n;i++) {
        ans=ans+a*i*((ull)(n-i-1)*(n-i-2)/2);
        ans=ans+b*i*(n-i-1)*i;
        ans=ans+c*i*((ull)i*(i-1)/2);
    }
    for (int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        x[i]=u; y[i]=v;
        h[u].push_back(v);
        h[v].push_back(u);
        if (u>v) swap(u,v);
        ans-=(b*u+c*v)*u+a*((ull)u*(u-1)/2);
        ans-=(a*u+c*v)*(v-u-1)+b*((ull)(u+v)*(v-u-1)/2);
        ans-=(a*u+b*v)*(n-v-1)+c*((ull)(v+n)*(n-v-1)/2);
    }
    for (int i=0;i<n;i++)
    {
        sz[i]=h[i].size(); r=0;
        sort(h[i].begin(),h[i].end());
        for (int j=0;j<h[i].size();j++){
            d=h[i][j];
            if (d<i) ans+=a*d*(sz[i]-j-1)+b*d*j,r++;
            else ans+=b*d*(sz[i]-j-1)+c*d*j;
        }
        ans+=c*i*((ull)(r*(r-1)/2))+b*i*r*(sz[i]-r)+a*i*((ull)(sz[i]-r)*(sz[i]-r-1)/2);
    }
    for (int i=0;i<m;i++)
    {
        u=x[i]; v=y[i];
        if (sz[u]<sz[v]||sz[u]==sz[v]&&u<v) swap(u,v);
        g[v].push_back(u);
    }
    for (int i=0;i<n;i++) sort(g[i].begin(),g[i].end());
    for (int i=0;i<m;i++)
    {
        u=x[i]; v=y[i]; s=0; t=0;
        while (s<g[u].size()&&t<g[v].size()){
            if (g[u][s]==g[v][t]) ans-=calc(u,v,g[u][s]),s++,t++;
            else if (g[u][s]>g[v][t]) t++; else s++;
        }
    }
    cout << ans << endl;
}