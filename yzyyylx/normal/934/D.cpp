#include<bits/stdc++.h>
#define ll long long
#define N 2010
using namespace std;

ll k,p;
vector<ll>g,f;

int main()
{
    ll i,j,t,b;
    cin>>p>>k;
    t=-p/k;
    for(;t;)
    {
	g.push_back(t);
	b=t;
	t=-t/k;
	if(t*k+b<0) t++;
    }
//    for(i=g.size()-1;i>=0;i--) cout<<g[i]<<" ";puts("");
    f.resize(g.size()+1);
    f[0]=p;
    for(i=0;i<g.size();i++) f[i]+=g[i]*k;
    for(i=0;i<g.size();i++) f[i+1]+=g[i];
    cout<<f.size()<<endl;
    for(i=0;i<f.size();i++) printf("%lld ",f[i]);
}