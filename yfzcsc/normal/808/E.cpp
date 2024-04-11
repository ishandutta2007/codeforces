#include<bits/stdc++.h>
#define maxn 300010
using namespace std;
typedef long long ll;
vector<int> v[4];
ll w[4][maxn],f[maxn],g[maxn],ls[maxn];
int n,m,ptr[maxn],tp;
void solve(int l,int r,int ql,int qr,int x){
	if(l>r)return ;
	int mid=l+r>>1,pos;
	ll mx=-1ll<<60,mxpos=0;
//	printf("\n{%d,%d,%d,%d}",l,r,ql,qr);
	for(pos=ql;pos<mid&&pos<=qr;pos++)
		if(mid-pos<=ptr[x]&&mx<ls[pos]+w[x][mid-pos])
			mx=ls[pos]+w[x][mid-pos],mxpos=pos;//,printf("[%d:%d]",x,mid-pos);
//	printf("[%lld]",mx);
	g[mid]=max(ls[mid],mx);
	solve(l,mid-1,ql,mxpos,x);
	solve(mid+1,r,mxpos,qr,x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,wi,ci;i<=n;++i)
		scanf("%d%d",&wi,&ci),v[wi].push_back(ci);
	for(int i=1;i<=3;++i){
		sort(v[i].begin(),v[i].end(),greater<int>());
		for(int j=0;j<v[i].size();++j)
			w[i][ptr[i]+1]=w[i][ptr[i]]+v[i][j],ptr[i]++;
	}
	for(int i=1;i<=3;++i)
		for(int j=0;j<i;++j){
			tp=0;
			for(int k=j;k<=m;k+=i)ls[++tp]=f[k];
			solve(2,tp,1,tp,i);
			for(int k=j,l=1;k<=m;k+=i,l++)f[k]=max(f[k],g[l]);//,printf("<%d,%lld>",k,f[k]);
		}
	printf("%lld",f[m]);
}