#include<bits/stdc++.h>
using namespace std;
int n,A[4],dp[1010][4][4][4][4];
char s[4][1010];
int pos[4];
void upd(int &x,int y){
	x=x<y?x:y;
}
void dfs(int L,int p,int a[4],int v){
	if (p==4){
		for (int i=0;i<4;i++) a[i]=max(a[i],0);
		upd(dp[L][a[0]][a[1]][a[2]][a[3]],v);
		return;
	}
	if (s[p][L]=='.'||a[p]>=0) dfs(L,p+1,a,v);
	int b[4];
	for (int i=0;p+i<4;i++){
		for (int j=0;j<4;j++) b[j]=a[j];
		for (int j=p;j<=i+p;j++) b[j]=max(b[j],i);
		dfs(L,p+1,b,v+A[i]);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<4;i++)
		scanf("%d",&A[i]);
	for (int i=0;i<4;i++)
		scanf("%s",s[i]+1);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0][0][0]=0;
	for (int i=0;i<n;i++)
		for (int a=0;a<4;a++)
			for (int b=0;b<4;b++)
				for (int c=0;c<4;c++)
					for (int d=0;d<4;d++)
						if (dp[i][a][b][c][d]<1e9){
							pos[0]=a-1; pos[1]=b-1;
							pos[2]=c-1; pos[3]=d-1;
							dfs(i+1,0,pos,dp[i][a][b][c][d]);
						}
	printf("%d\n",dp[n][0][0][0][0]);
}