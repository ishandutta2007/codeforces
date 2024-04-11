#include<bits/stdc++.h>
using namespace std;

int n,sz[1010][1010],cnt[1010],in[1010][1010],tot=0,used[1010];
queue<int>q;
struct R{
	int from,to,nex;
}r[2333];
int ecnt=1,hea[1010]={0};

void dfs(int x,int fff,int rt){
	if (fff!=rt&&in[x][rt]!=in[fff][rt]) exit(0*puts("-1"));
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to; if (y==fff) continue;
		dfs(y,x,rt);
	}
}

int main(){
	scanf("%d",&n);
	int las,k,x;
	for (int i=1;i<=n;i++){
		for (las=n-1;las;las-=k){
			scanf("%d:",&k);
			cnt[i]++;
			sz[i][cnt[i]]=k;
			for (int j=1;j<=k;j++){
				scanf("%d",&x);
				in[x][i]=cnt[i];
				if (j!=k) scanf(",");
			}
			if (las) scanf("-");
		}
		if (cnt[i]==1) q.push(i);
		tot+=cnt[i];
	}
	
	for (int fl;!q.empty();){
		x=q.front();q.pop();
		cnt[x]=0;
		fl=0;
		for (int i=1;i<=n;i++){
			if (!cnt[i]) continue;
			if (sz[i][in[x][i]]==1){
				r[++ecnt]=(R){x,i,hea[x]};hea[x]=ecnt;
				r[++ecnt]=(R){i,x,hea[i]};hea[i]=ecnt;
				fl++;
			}
		}
		for (int i=1;i<=n;i++){
			if (!cnt[i]) continue;
			if (sz[i][in[x][i]]){
				sz[i][in[x][i]]--;
				if (sz[i][in[x][i]]==0){
					cnt[i]--;
					if (cnt[i]==1){
						q.push(i);
					}
				}
			}
		}
	}
	if (ecnt!=(n*2-1)) return 0*puts("-1");
	for (int x=1;x<=n;x++){
		memset(used,0,sizeof used);
		int y;
		for (int i=hea[x];i>0;i=r[i].nex){
			y=r[i].to;
			if (used[in[y][x]]++) return 0*puts("-1");
			dfs(y,x,x);
		}
	}
	printf("%d\n",n-1);
	for (int i=1;i<n;i++){
		printf("%d %d\n",r[i<<1].from,r[i<<1].to);
	}
}