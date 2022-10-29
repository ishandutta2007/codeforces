#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 8010
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int n,m,anses[maxn],a[maxn][maxn],R,pi[10],ptr;
map<pii,int>st;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	scanf("%d",&R);
	int sum=0;
	for(int i=0;i<4;++i)scanf("%d",&pi[i]),sum=(sum+pi[i])%mod;
	sum=qpow(sum,mod-2);
	for(int i=0;i<4;++i)pi[i]=(ll)pi[i]*sum%mod;
	for(int i=-R;i<=R;++i)
		for(int j=-R;j<=R;++j)
			if(i*i+j*j<=R*R)st[pii(i,j)]=++ptr;
	for(auto p:st){
		a[p.second][p.second]++;
		for(int i=0;i<4;++i){
			int px=p.first.first+dx[i];
			int py=p.first.second+dy[i];
			if(st.find(pii(px,py))==st.end())continue;
			a[p.second][st[pii(px,py)]]=mod-pi[i];
		}
		a[p.second][ptr+1]++;
	}
	for(int i=1,j=1;i<=ptr;++i){
		for(j=i;j<=ptr&&!a[j][i];++j);
		if(j==ptr+1)continue;
		for(int k=i;k<=ptr+1;++k)swap(a[j][k],a[i][k]);
		int iv=qpow(a[i][i],mod-2);
		vector<int>f;
		for(int k=i;k<=ptr+1;++k)if(a[i][k])f.push_back(k);
		for(int k=i;k<=ptr;++k)if(i!=k&&a[k][i]){
			int t=1ll*a[k][i]*iv%mod;
			for(auto p:f)a[k][p]=(a[k][p]-(ll)t*a[i][p]%mod+mod)%mod;
		}
	}
	int z=st[pii(0,0)];
	for(int i=ptr;i>=z;--i){
		int b=a[i][ptr+1];
		for(int j=ptr;j>=i;--j)
			if(a[i][j])b=(b-(ll)a[i][j]*anses[j]%mod+mod)%mod;
		anses[i]=(ll)b*qpow(a[i][i],mod-2)%mod;
	}
	printf("%d",anses[z]);
}