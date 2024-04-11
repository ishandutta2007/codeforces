#include<bits/stdc++.h>
using namespace std;

int n,m,ch[10000001][2]={0},cnt=1;
vector<int>v[10000001];

void dfs(int x,int dep){
	for (int i=0;i<=(1<<dep);i++){
		v[x].push_back(0);
	}
	if (dep==0){
		v[x][0]=1;
		return;
	}
	for (int i=0;i<2;i++){
		if (ch[x][i]){
			dfs(ch[x][i],dep-1);
		}
	}
	int c,d;
	for (int i=0;i<(1<<dep);i++){
		c=i&(1<<(dep-1))?1:0;
		d=(i|(1<<(dep-1)))^(1<<(dep-1));
		if (!ch[x][c]){
			v[x][i]=0;
		}else{
			if ( !ch[x][c^1] || v[ch[x][c]][d] < (1<<(dep-1)) ){
				v[x][i]=v[ch[x][c]][d];
			}else{
				v[x][i]=(1<<(dep-1))+v[ch[x][c^1]][d];
			}
		}
	}
	//printf(" %d: ",x);for (int i=0;i<(1<<dep);i++) printf("%d ",v[x][i]);printf("\n");
}

int main(){
	int x,t=0,c,p;
	scanf("%d%d",&n,&m);
	for (;n--;){
		scanf("%d",&x);
		p=1;
		for (int i=19;i>=0;i--){
			c=((1<<i)&x)?1:0;
			if (!ch[p][c]){
				ch[p][c]=++cnt;
			}
			p=ch[p][c];
		}
	}
	dfs(1,20);
	
	for (;m--;){
		scanf("%d",&x);
		t^=x;
		printf("%d\n",v[1][t]);
	}
}