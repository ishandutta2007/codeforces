#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct P{
	int x,y;
	friend P operator -(const P &a,const P &b){
		return (P){a.x-b.x,a.y-b.y};
	}
	friend P operator +(const P &a,const P &b){
		return (P){a.x+b.x,a.y+b.y};
	}
	friend ll operator *(const P &a,const P &b){
		return 1ll*a.x*b.y-1ll*a.y*b.x;
	}
}a[10],b[1005];
vector<int> path[10][1005];
int n,K,key,ans,ord[10],otot;
int vis[10],ok[1005],T;
ll dot(const P &a,const P &b){
	return 1ll*a.x*b.x+1ll*a.y*b.y;
}
bool on(const P &x,const P &y,const P &z){
	if ((x-y)*(x-z)) return 0;
	return dot(x-y,z-y)>0&&dot(x-z,y-z)>0;
}
bool check(int b){
	if (otot==K+1) return 0;
	int now=ord[otot++];
	for (int i=0;i<path[now][b].size();i++)
		if (ok[path[now][b][i]]!=T){
			if (!check(path[now][b][i])) return 0;
		}
	ok[b]=T;
	return 1;
}
bool dfs(int now){
	if (now==K+1){
		++T;
		otot=1;
		return check(key);
	}
	bool ret=0;
	for (int i=1;i<=K&&!ret;i++)
		if (!vis[i]){
			vis[i]=1;
			ord[now]=i;
			ret=dfs(now+1);
			vis[i]=0;
		}
	return ret;
}
int main(){
	scanf("%d%d",&K,&n);
	for (int i=1;i<=K;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&b[i].x,&b[i].y);
	for (int i=1;i<=K;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				if (on(b[k],a[i],b[j]))
					path[i][j].push_back(k);
	for (key=1;key<=n;key++)
		if (dfs(1)) ans++;
	printf("%d",ans);
}