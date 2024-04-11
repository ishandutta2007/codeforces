#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k,f[50100][510];
ll ans=0;
struct R{
	int to,nex;
}r[101000];
int hea[50100],cnt=1;

void dfs(int x,int fff){
	f[x][0]=1;
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to; if (y==fff) continue;
		dfs(y,x);
		for (int u=0;u<k;u++)
			ans+=(ll)f[x][u]*f[y][k-1-u];
		for (int u=0;u<k;u++)
			f[x][u+1]+=f[y][u];
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for (int x,y,ttt=n-1;ttt--;){
		scanf("%d%d",&x,&y);
		r[++cnt]=(R){y,hea[x]}; hea[x]=cnt;
		r[++cnt]=(R){x,hea[y]}; hea[y]=cnt;
	}
	dfs(1,0);
	cout<<ans;
}