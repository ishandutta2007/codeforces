#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,mp[23][23]={0},now;
ll f[19][1<<19],ans=0;

inline ll dfs(int x,int z){
	bool b=(z&-z)==z;
	z|=1<<x;
	if (f[x][z]!=-1) return f[x][z];
	ll t=0;
	for (int y=now;y<n;y++){
		if (!mp[x][y]) continue;
		if (y==now&&!b) t++;
		if (z&(1<<y)) continue;
		t+=dfs(y,z);
	}
	return f[x][z]=t;
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for (;m--;){
		scanf("%d%d",&x,&y);
		x--;y--;
		mp[x][y]=mp[y][x]=1;
	}
	
	for (now=0;now<n;now++){
		memset(f,-1,sizeof f);
		ans+=dfs(now,0);
	}
	printf("%I64d\n",ans>>1);
}