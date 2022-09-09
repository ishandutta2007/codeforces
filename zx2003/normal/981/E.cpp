#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,q,l,r,x,i;
vector<int>t[N<<2];
void add(int i,int x,int y,int l,int r,int v){
	if(x==l && y==r){
		t[i].push_back(v);
		return;
	}
	int m=(x+y)>>1;
	if(l>m)add(i<<1|1,m+1,y,l,r,v);
		else if(r<=m)add(i<<1,x,m,l,r,v);
				else add(i<<1,x,m,l,m,v),add(i<<1|1,m+1,y,m+1,r,v);
}
bitset<N>f[20],ans;
void dfs(int i,int l,int r,int dep){
	f[dep]=f[dep-1];
	for(int j=0;j<t[i].size();++j)f[dep]|=f[dep]<<t[i][j];
	if(l==r){
		ans|=f[dep];
		return;
	}
	int m=(l+r)>>1;
	dfs(i<<1,l,m,dep+1);dfs(i<<1|1,m+1,r,dep+1);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(i=1;i<=q;++i){
		cin>>l>>r>>x;
		add(1,1,n,l,r,x);
	}
	f[0][0]=1;
	dfs(1,1,n,1);
	int cnt=0;
	for(i=1;i<=n;++i)if(ans[i])++cnt;
	cout<<cnt<<'\n';
	for(i=1;i<=n;++i)if(ans[i])cout<<i<<' ';
	return 0;
}