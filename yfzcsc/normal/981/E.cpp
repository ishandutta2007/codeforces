#include<bits/stdc++.h>
#define maxn 10010
using namespace std;
bitset<maxn>ans;
vector<int>G[maxn<<2];
int n,Q;
void mdy(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr){
		G[o].push_back(x);
		return ;
	}
	int mid=l+r>>1;
	if(ql<=mid)mdy(o<<1,l,mid,ql,qr,x);
	if(qr>mid)mdy(o<<1|1,mid+1,r,ql,qr,x);
}
void dfs(int o,int l,int r,bitset<maxn>bs){
	for(auto p:G[o])bs|=bs<<p;
	if(l==r){ans|=bs;return ;}
	int mid=l+r>>1;
	dfs(o<<1,l,mid,bs);
	dfs(o<<1|1,mid+1,r,bs);
}
int main(){
	scanf("%d%d",&n,&Q);
	for(int i=1,l,r,x;i<=Q;++i){
		scanf("%d%d%d",&l,&r,&x);
		mdy(1,1,n,l,r,x);
	}
	bitset<maxn>bs;
	bs.reset(),bs[0]=1;
	dfs(1,1,n,bs);
	int cnt=0;
	for(int i=1;i<=n;++i)cnt+=ans[i];
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i)if(ans[i])printf("%d ",i);
}