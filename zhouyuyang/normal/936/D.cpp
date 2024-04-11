#include<bits/stdc++.h>
#define N 4000005
using namespace std;
int x1[N],x2[N],x[N];
int dp[2][N],pre[2][N];
int a[2][N],n,m1,m2,t;
int m,ans;
void upd(int i,int j,int y,int z){
	if (y>dp[i][j]){
		dp[i][j]=y;
		pre[i][j]=z;
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m1,&m2,&t);
	for (int i=1;i<=m1;i++){
		scanf("%d",&x1[i]);
		x[++m]=x1[i]; x[++m]=x1[i]+1;
	}
	for (int i=1;i<=m2;i++){
		scanf("%d",&x2[i]);
		x[++m]=x2[i]; x[++m]=x2[i]+1;
	}
	x[++m]=1; x[++m]=n+1;
	sort(x+1,x+m+1);
	m=unique(x+1,x+m+1)-x-1;
	for (int i=1;i<=m1;i++)
		a[0][lower_bound(x+1,x+m+1,x1[i])-x]=1;
	for (int i=1;i<=m2;i++)
		a[1][lower_bound(x+1,x+m+1,x2[i])-x]=1;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=dp[1][0]=0; pre[1][0]=1;
	for (int i=0;i<m;i++){
		for (int w=0;w<2;w++)
			if (dp[w][i]!=-1&&!a[w^1][i])
				upd(w^1,i,min(dp[w][i],t),1);
		for (int w=0;w<2;w++)
			if (dp[w][i]!=-1&&dp[w][i]+x[i+1]-x[i]-1>=t*a[w][i+1])
				upd(w,i+1,dp[w][i]+x[i+1]-x[i]-t*a[w][i+1],0);
	}
	int w=(dp[1][m]>dp[0][m]);
	if (dp[w][m]==-1)
		return puts("No"),0;
	puts("Yes");
	vector<int> A;
	#define pa pair<int,int>
	vector<pa > B;
	int la=1e9;
	for (int i=w,j=m;i||j;)
		if (pre[i][j]) A.push_back(x[j]),i^=1;
		else{
			if (a[i][j]){
				la=min(la-t,x[j]-1);
				B.push_back(pa(la,i+1));
			}
			j--;
		}
	printf("%d\n",A.size());
	for (int i=A.size()-1;i>=0;i--)
		printf("%d ",A[i]);
	printf("\n%d\n",B.size());
	for (int i=B.size()-1;i>=0;i--)
		printf("%d %d\n",B[i].first,B[i].second);
}