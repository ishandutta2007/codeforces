#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 100100
using namespace std;
typedef pair<int,int> par;
const int inf=(int)1e9+100;
vector<int>vec[maxn];
vector<par>Q[maxn];
int n,a[maxn],m,s[maxn],anses[maxn],pw[maxn],val[maxn],f[maxn],rel[maxn];
int get(int l,int r){return l>r?0:(s[l]-1ll*s[r+1]*pw[r-l+1])%mod;}
int find(int x){
	if(x==f[x])return x;
	int y=f[x];
	f[x]=find(y);
	rel[x]=(rel[x]+rel[y])%mod;
	return f[x];
}
int main(){
	scanf("%d%d",&n,&m),pw[0]=1;
	for(int i=1;i<=n;++i)
		pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1;i<=n;++i)	
		scanf("%d",&a[i]);
	for(int i=n;i>=1;--i)
		s[i]=(s[i+1]*2ll+a[i])%mod;
	for(int i=1;i<=n;++i){
		long long nw=0,ret=0;
		for(int j=i;j>=1;--j){
			nw=nw*2+a[j];
			if(nw>=inf)break;
			if(nw<=0){ret=j-1,val[i]=nw*2ll%mod;break;}
		}
		if(ret)vec[ret].push_back(i);//,printf("[%d,%d]\n",ret,i);
	}
	for(int i=1,l,r;i<=m;++i){
		scanf("%d%d",&l,&r);
		if(l==r)anses[i]=a[l];
		else Q[l].push_back(par(r,i));
	}
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=n;i>=1;--i){
		for(int j=0;j<Q[i].size();++j){
			int x=find(Q[i][j].first);
		//	printf("[%d,%d]",i,x);
			anses[Q[i][j].second]=(rel[Q[i][j].first]+get(i,x))%mod;
		}
		for(int j=0;j<vec[i].size();++j){
			f[vec[i][j]]=i;
			rel[vec[i][j]]=val[vec[i][j]];
		}
	}
	for(int i=1;i<=m;++i)printf("%d\n",(anses[i]%mod+mod)%mod);
}