#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;	
}
const int N=5e5+5,mod=1e9+9;
#define lowbit(x) ((x)&-(x))
int n,m,tot,dep[N],L[N],R[N];
char ch[N];
vector<int>G[N],sum[N],p[N];
void dfs(int x){
	sum[dep[x]].push_back(1<<(ch[x]-'a'));
	L[x]=++tot;p[dep[x]].push_back(tot);
	for(auto y:G[x])dfs(y);
	R[x]=tot;
}
int main(){
	n=read(),m=read();dep[1]=1;
	for(int i=2;i<=n;i++){
		int fa=read();
		G[fa].push_back(i);
		dep[i]=dep[fa]+1;
	}
	scanf("%s",ch+1);dfs(1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<(int)sum[i].size();j++)
			sum[i][j]^=sum[i][j-1];
	while(m--){
		int x=read(),d=read();
		if(d>n){puts("Yes");continue;}
		int num=sum[d].size();
		if(!num){puts("Yes");continue;}
		int ll=0,rr=num-1,mid,l,r;
		while(ll<=rr){
			mid=(ll+rr)>>1;
			if(p[d][mid]>=L[x])rr=mid-1;
			else ll=mid+1;
		}
		l=ll;ll=0,rr=num-1;
		while(ll<=rr){
			mid=(ll+rr)>>1;
			if(p[d][mid]<=R[x])ll=mid+1;
			else rr=mid-1;
		}
		r=rr;
		if(l>r){puts("Yes");continue;}
		int res=sum[d][r];
		if(l>0)res^=sum[d][l-1];
		if(!res || !(res-lowbit(res)))puts("Yes");
		else puts("No");
	}
	return 0;
}