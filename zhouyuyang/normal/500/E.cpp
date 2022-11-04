#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,top,sta[N],se[N][2];
int nxt[N][20],cost[N][20];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",&se[i][0],&se[i][1]);
		se[i][1]+=se[i][0];
		for (;top;){
			if (se[i][1]<=se[sta[top-1]][1]) break;
			nxt[sta[--top]][0]=i;
		}
		sta[top++]=i;
	}
	for (;top;nxt[sta[--top]][0]=n);
	nxt[n][0]=n;
	for (int i=0;i<=n;i++){
		int j=nxt[i][0];
		if (j==n||se[j][0]<se[i][1]) cost[i][0]=0;
		else cost[i][0]=se[j][0]-se[i][1];
	}
	for (int t=1;t<20;t++)
		for (int i=0;i<=n;i++){
			int j=nxt[i][t-1];
			nxt[i][t]=nxt[j][t-1];
			cost[i][t]=cost[i][t-1]+cost[j][t-1];
		}
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x--; y--; int ans=0;
		for (int t=19;t>=0;t--)
			if (nxt[x][t]<=y){
				ans+=cost[x][t];
				x=nxt[x][t];
			}
		printf("%d\n",ans);
	}
}