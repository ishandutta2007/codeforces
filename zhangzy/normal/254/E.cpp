#include<bits/stdc++.h>
using namespace std;
int f[438][438],pre[438][438],cst[438][438],n,k,m,a[520],ans,anw;
int g[438][941];
struct Node{
	int pos,val;
};
vector<Node>vec[666];

bool cmp(Node nd1,Node nd2){
	return nd1.val<nd2.val;
}

void prepare(int w){
	memset(g[w],0,sizeof(g[w]));
	sort(vec[w].begin(),vec[w].end(),cmp);
	int tot=0,sz=vec[w].size();
	for (int i=0;i<sz;i++){
		tot+=vec[w][i].val;
		if (tot>800) break;
		g[w][tot]++;
	}
	for (int i=1;i<=800;i++){
		g[w][i]+=g[w][i-1];
	}
}

void pri(int x,int w){
	if (x<=0) return;
	pri(x-1,pre[x][w]);
	printf("%d",cst[x][w]);
	for (int i=0;i<cst[x][w];i++){
		printf(" %d",vec[x][i].pos);
	}
	printf("\n");
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x,y,z;
	scanf("%d%d",&n,&k);
	a[0]=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		for (int j=x;j<=y;j++){
			vec[j].push_back((Node){i,z});
		}
	}
	for (int i=1;i<=n;i++){
		prepare(i);
	}
	memset(f,-38,sizeof(f));
	f[0][0]=0;
	int u,v,t;
	for (u=0;u<n;u++){
		v=u+1;
		for (int i=0;i<=a[u];i++){
			if (f[u][i]>=0){
				for (int j=(i+a[v]-k);j>=0;j--){
					t=min(i+a[v]-k-j,a[v]);
					if (f[u][i]+g[v][j]>f[v][t]){
						f[v][t]=f[u][i]+g[v][j];
						pre[v][t]=i;
						cst[v][t]=g[v][j];
					}
				}
			}
		}
	}
	
	for (int i=0;i<=a[n];i++){
		if (f[n][i]>ans){
			ans=f[n][i];
			anw=i;
		}
	}
	printf("%d\n",ans);
	pri(n,anw);
}