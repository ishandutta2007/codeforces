#include<bits/stdc++.h>
using namespace std;
int n,m;
struct R{
	int to,val,nex;
}r[201000];
int hea[401000]={0},cnt=1;
int d[201000],ans;

vector<int>v[30];
void add(int x){
	if (x==0) return;
	int t=29;
	while (!(x&(1<<t))) t--;
	v[t].push_back(x);
}

void dfs(int x){
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to;
		if (d[y]==-1){
			d[y]=d[x]^r[i].val;
			dfs(y);
		}else{
			add(d[x]^d[y]^r[i].val);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y,z;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		r[++cnt]=(R){y,z,hea[x]};hea[x]=cnt;
		r[++cnt]=(R){x,z,hea[y]};hea[y]=cnt;
	}
	memset(d,-1,sizeof d);
	d[n]=0;
	dfs(n);
	
	if (d[1]==-1){puts("-1");return 0;}
	ans=d[1];
	for (int i=29;i>=0;i--){
		if (ans&(1<<i)){
			if (v[i].size()){
				ans^=v[i][0];
			}
		}
		for (int j=1;j<(int)v[i].size();j++){
			add(v[i][0]^v[i][j]);
		}
	}
	printf("%d\n",ans);
}