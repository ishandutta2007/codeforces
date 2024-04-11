#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int n,x[101000],y[101000],fa[101000],sz[101000],tot[101000],u,v;
map<int,vector<int> >xx,yy;
map<int,vector<int> >::iterator it;
ll ans=1,er[202000];

int GF(int x){
	return fa[x]==x? x: fa[x]=GF(fa[x]);
}

void doit(vector<int> &the){
	for (int i=1;i<(int)the.size();i++)
		if ( (u=GF(the[i-1])) != (v=GF(the[i])) ){
			sz[v]+=sz[u];
			tot[v]+=tot[u];
			fa[u]=v;
		}
	tot[GF(the[0])]++;
}

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		xx[x[i]].push_back(i); yy[y[i]].push_back(i);
		fa[i]=i; sz[i]=1;
	}
	for (it=xx.begin();it!=xx.end();it++) doit(it->second);
	for (it=yy.begin();it!=yy.end();it++) doit(it->second);
	er[0]=1;
	for (int i=1;i<202000;i++) er[i]=er[i-1]*2%mod;
	for (int i=1;i<=n;i++)
		if (fa[i]==i)
			ans=ans*(er[tot[i]]-(tot[i]>sz[i]))%mod;
	cout<<(ans+mod)%mod;
	
}