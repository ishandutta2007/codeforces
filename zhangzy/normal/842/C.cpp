#include<bits/stdc++.h>
using namespace std;

int n,a[520233];
struct R{
	int to,nex;
}r[520233];
int hea[520233]={0},cnt=1,f[520233],g[520233];
vector<int>v[520233];

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

void dfs(int x,int fa){
	int y,t,mx,fl;
	v[x].clear();
	mx=g[x]=gcd(a[x],g[fa]);
	v[x].push_back(g[x]);
	for (int i=0;i<v[fa].size();i++){
		t=gcd(a[x],v[fa][i]);
		mx=max(t,mx);
		fl=1;
		for (int j=0;j<v[x].size();j++){
			if (t%v[x][j]==0){
				swap(t,v[x][j]);fl=0;break;
			}
			if (v[x][j]%t==0){
				fl=0;break;
			}
		}
		if (fl){
			v[x].push_back(t);
		}
	}
	f[x]=max(mx,g[fa]);
	v[x].push_back(g[fa]);
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to;
		if (y==fa) continue;
		dfs(y,x);
	}
}

int main(){
	int x,y;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		r[++cnt]=(R){y,hea[x]};
		hea[x]=cnt;
		r[++cnt]=(R){x,hea[y]};
		hea[y]=cnt;
	}
	dfs(1,0);
	for (int i=1;i<=n;i++){
		printf("%d ",f[i]);
	}
}