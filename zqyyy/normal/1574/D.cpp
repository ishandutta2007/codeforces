#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=11,M=2e5+7;
int n,c[N],a[N][M];
int m,b[M][N];
bool v[N];
int num;
vector<int>p,ans;
map<vector<int>,bool>h;
priority_queue<pair<int,pair<int,int> > >q;
bool dfs(int x,int sum){
	int res=sum;
	priority_queue<pair<int,pair<int,int> > >Q=q;
	while(!Q.empty())res+=Q.top().first,Q.pop();
	if(res<=num)return 0;
	if(x==n){
		if(h.count(p))return 1;
		num=sum,ans=p;
		return 0;
	}
	Q=q;
	while(!q.empty()){
		int u=q.top().second.first,v=q.top().second.second;q.pop();
		p[v]=u;
		if(!dfs(x+1,sum+a[v][u])){q=Q;return 1;}
		if(u>1)u--,q.push({a[v][u],{u,v}});
		else {q=Q;return 1;}
	}
	q=Q;
	return 1;
}
int main(){
	n=read();
	for(int i=0;i<n;i++){
		c[i]=read();
		for(int j=1;j<=c[i];j++)a[i][j]=read();	
	}
	m=read(),p.resize(n);
	for(int i=1;i<=m;i++){
		vector<int>b(n);
		for(int j=0;j<n;j++)b[j]=read();
		h[b]=1;
	}
	for(int i=0;i<n;i++)q.push({a[i][c[i]],{c[i],i}});
	dfs(0,0);
	for(int x:ans)printf("%d ",x);
	return 0;
}