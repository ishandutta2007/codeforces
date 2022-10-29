#include<bits/stdc++.h>
#define maxn 35100
using namespace std;
typedef unsigned short unt;
struct segment{
	unt s[maxn<<2],addv[maxn<<2];
	void pushdown(int o){
		if(addv[o]){
			addv[o<<1]+=addv[o];
			addv[o<<1|1]+=addv[o];
			s[o<<1]+=addv[o];
			s[o<<1|1]+=addv[o];
			addv[o]=0;
		}
	}
	void modify(int o,int l,int r,int ql,int qr,int k){
		if(ql<=l&&r<=qr){s[o]+=k,addv[o]+=k;return ;}
		int mid=l+r>>1;
		pushdown(o);
		if(ql<=mid)modify(o<<1,l,mid,ql,qr,k);
		if(qr>mid)modify(o<<1|1,mid+1,r,ql,qr,k);
		s[o]=max(s[o<<1],s[o<<1|1]);
	}
}A[50];
int dp[maxn][51],n,k,a[maxn],lst[maxn],z[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)z[i]=0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),lst[i]=z[a[i]],z[a[i]]=i;
	for(int i=1;i<=n;++i){
		for(int j=min(i,k);j>=1;--j){
			A[j-1].modify(1,0,n,lst[i],i-1,1);
			dp[i][j]=A[j-1].s[1];
		//	printf("[(%d,%d)%d,%d,%d]\n",z[i],i,i,j,dp[i][j]);
			if(j<k)A[j].modify(1,0,n,i,i,dp[i][j]);
		}	
	}
	printf("%d",dp[n][k]);
}